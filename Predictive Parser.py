import collections

EPSILON = "ε"

class PredictiveParser:
    def __init__(self, grammar):
        self.grammar = grammar
        self.first_sets = collections.defaultdict(set)
        self.follow_sets = collections.defaultdict(set)
        self.parsing_table = {}

    def compute_first_sets(self):
        for non_terminal in self.grammar:
            self.first(non_terminal)

    def first(self, symbol):
        if symbol in self.first_sets:
            return self.first_sets[symbol]

        first_set = set()
        if symbol not in self.grammar:  # Terminal
            first_set.add(symbol)
        else:
            for production in self.grammar[symbol]:
                for item in production:
                    first_set |= self.first(item)
                    if EPSILON not in self.first_sets[item]:
                        break
                else:
                    first_set.add(EPSILON)

        self.first_sets[symbol] = first_set
        return first_set

    def compute_follow_sets(self, start_symbol):
        self.follow_sets[start_symbol].add("$")  # End of input marker
        for non_terminal in self.grammar:
            self.follow(non_terminal)

    def follow(self, symbol):
        for nt, productions in self.grammar.items():
            for production in productions:
                for i, item in enumerate(production):
                    if item == symbol:
                        next_symbols = production[i + 1:]
                        if next_symbols:
                            first_of_next = set()
                            for next_symbol in next_symbols:
                                first_of_next |= self.first(next_symbol)
                                if EPSILON not in self.first_sets[next_symbol]:
                                    break
                            else:
                                first_of_next.add(EPSILON)

                            self.follow_sets[symbol] |= first_of_next - {EPSILON}

                        if not next_symbols or EPSILON in first_of_next:
                            self.follow_sets[symbol] |= self.follow_sets[nt]

    def construct_parsing_table(self):
        for non_terminal, productions in self.grammar.items():
            for production in productions:
                first_of_production = set()
                for symbol in production:
                    first_of_production |= self.first(symbol)
                    if EPSILON not in self.first_sets[symbol]:
                        break
                else:
                    first_of_production.add(EPSILON)

                for terminal in first_of_production - {EPSILON}:
                    self.parsing_table[(non_terminal, terminal)] = production

                if EPSILON in first_of_production:
                    for terminal in self.follow_sets[non_terminal]:
                        self.parsing_table[(non_terminal, terminal)] = production

    def generate_parser_code(self):
        parser_code = "def parse(tokens):\n"
        parser_code += "    stack = ['$', 'S']\n"
        parser_code += "    pointer = 0\n\n"
        parser_code += "    while stack:\n"
        parser_code += "        top = stack.pop()\n"
        parser_code += "        if top == '$' and pointer == len(tokens):\n"
        parser_code += "            print('Accepted')\n"
        parser_code += "            return\n"
        parser_code += "        elif top in tokens[pointer:]:\n"
        parser_code += "            pointer += 1\n"
        parser_code += "        elif (top, tokens[pointer]) in table:\n"
        parser_code += "            stack.extend(reversed(table[(top, tokens[pointer])]))\n"
        parser_code += "        else:\n"
        parser_code += "            print('Syntax Error')\n"
        parser_code += "            return\n"

        return parser_code

# Example usage:
grammar = {
    "S": [["A", "B"]],
    "A": [["a"], ["ε"]],
    "B": [["b"], ["ε"]]
}

parser = PredictiveParser(grammar)
parser.compute_first_sets()
parser.compute_follow_sets("S")
parser.construct_parsing_table()
parser_code = parser.generate_parser_code()

print("Generated Parser Code:\n")
print(parser_code)
