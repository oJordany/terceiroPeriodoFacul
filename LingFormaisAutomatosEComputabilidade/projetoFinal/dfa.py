import string
import copy

class DFA:
    def __init__(self, alphabet:set, states:set, initialState:str, finalState:str):
        self.alphabet = alphabet
        self.states = states
        self.initialState = initialState
        self.finalState = finalState 

    def setTransitionFunction(self, transitions:dict):
        pass

    def run(self, string):
        pass


I = {*(string.ascii_letters + "_")}
M = {*(string.ascii_letters + string.digits + "_")}
MDI = M.difference(I)
IUM = I.union(M)

dfa = DFA(
    alphabet=IUM,
    states={"q0", "q1", "qf"},
    initialState="q0",
    finalState="qf"
    )

transitions = {}

transitions["q0"] = {
                    symbol: "q1" if not symbol.isdigit() and symbol != "," and symbol != ";" 
                    else None 
                    for symbol in M.union({",", ";"}) 
                    }

transitions["q1"] = {
                    symbol: "q1" if symbol != "," and symbol != ";" 
                    else "q0" if symbol == "," 
                    else "qf"
                    for symbol in M.union({",", ";"})
                    }

transitions["qf"] = {
                    symbol: None
                    for symbol in M.union({",", ";"})
                    }
