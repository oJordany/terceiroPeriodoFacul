import string

class DFA:
    def __init__(self, alphabet:set, states:set, transitions:dict,initialState:str, finalState:str):
        self.alphabet = alphabet
        self.states = states
        self.transitions = transitions
        self.initialState = initialState
        self.finalState = finalState 

    def splitEntryData(self, string:str):
        __primitiveType = string.split(" ", 1)[0]
        __variablesName = string.split(" ", 1)[1]
        __variablesName = ",".join([variable.strip() for variable in __variablesName.split(",")])
        return {"primitiveType": __primitiveType, "variablesName": __variablesName}
        

    def run(self, string:str):
        __currentState = self.initialState

        entryData = self.splitEntryData(string)

        for index, character in enumerate(entryData["variablesName"]):
            try:
                print(f"{__currentState} --- {character} --->", end=" ")
                __currentState = self.transitions[__currentState][character]  
                print(__currentState)  
            except KeyError as err:
                print("\n")
                if not err.args[0]:
                    print(f"o caracter '{entryData["variablesName"][index - 1]}' não pertence ao alfabeto")
                else:
                    print(f"o caracter '{character}' não pertence ao alfabeto")
                break
        
        if __currentState == self.finalState:
            print("palavra aceita")
        else:
            print("palavra recusada, pois não atinge o estado final")


I = {*(string.ascii_letters + "_")}
M = {*(string.ascii_letters + string.digits + "_")}
MDI = M.difference(I)
IUM = I.union(M)

print(I)
print(M)
print(MDI)

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

dfa = DFA(
    alphabet=IUM,
    states={"q0", "q1", "qf"},
    transitions=transitions,
    initialState="q0",
    finalState="qf"
    )

# dfa.run("testeDiferenciado, teste;")
dfa.splitEntryData("int testeDiferenciado, teste;")