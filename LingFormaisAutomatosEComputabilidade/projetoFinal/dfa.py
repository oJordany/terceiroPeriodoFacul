import string
import re

class DFA:
    def __init__(self, alphabet:set, states:set, transitions:dict,initialState:str, finalState:str):
        self.alphabet = alphabet
        self.states = states
        self.transitions = transitions
        self.initialState = initialState
        self.finalState = finalState 

    def splitEntryData(self, string:str):
        __allowedTypes = ["int", "char", "bool", "float", "double"]
        __primitiveType = string.split(" ", 1)[0]
        if __primitiveType in __allowedTypes:
            __variablesName = string.split(" ", 1)[1]
            __variablesList = [variable.strip() for variable in __variablesName.split(",")]
            __variablesList[-1] = re.sub(r"\s+;", ";", __variablesList[-1])
            __variablesName = ",".join(__variablesList)
            return {"primitiveType": __primitiveType, "variablesName": __variablesName}
        else:
            return f"Erro de Declaração de Tipo: {__primitiveType}"
        

    def run(self, string:str):
        __currentState = self.initialState

        entryData = self.splitEntryData(string)

        if type(entryData) == dict:
            for index, character in enumerate(entryData["variablesName"]):
                try:
                    # print(f"{__currentState} --- {character} --->", end=" ")
                    __currentState = self.transitions[__currentState][character]  
                    # print(__currentState)  
                except KeyError as err:
                    print("\n")
                    if not err.args[0]:
                        print(f"\033[1;31mo caracter '{entryData['variablesName'][index - 1]}' não pertence ao alfabeto\033[m")
                    else:
                        print(f"\033[1;31mo caracter '{character}' não pertence ao alfabeto\033[m")

                    break
            
            if __currentState == self.finalState:
                entryData["variablesName"] = re.sub(";", "", entryData["variablesName"])
                print("\033[1;32mpalavra aceita\033[m")
                print(f"Tipo primitivo: {entryData['primitiveType']}\nVariáveis: {entryData['variablesName'].split(',')}")
            else:
                print("\033[1;31mpalavra recusada\033[m")
        else:
            print(f'\033[1;31m{entryData}\033[m')


"""
MONTANDO A ESTRUTURA DA FUNÇÃO DE TRANSIÇÃO

transitions = {
    "q0":{
        "a": "q1", "b": "q1", ... ,"z": "q1", "A": "q1", "B": "q1", ... ,"Z": "q1", "_": "q1"
        },

    "q1":{
        "a": "q1", "b": "q1", ... ,"z": "q1", "A": "q1", "B": "q1", ... ,"Z": "q1", "_": "q1", 
        "0":"q1", "1": "q1", ... ,"9":"q1", ",": "q0", ";":"qf"
        },

    "qf":{
        "a": None, "b": None, ... ,"z": None, "A": None, "B": None, ... ,"Z": None, "_": None,
        "0": None, "1": None, ... ,"9": None, ",": None, ";": None
        }
    }
"""


I = {*(string.ascii_letters + "_")}
M = {*(string.ascii_letters + string.digits + "_")}
MDI = M.difference(I)
IUM = I.union(M)

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

# CRIANDO O AUTÔMATO
dfa = DFA(
    alphabet=IUM,
    states={"q0", "q1", "qf"},
    transitions=transitions,
    initialState="q0",
    finalState="qf"
    )

declaration = input()
dfa.run(declaration)