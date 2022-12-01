class DFA:

    def __init__(self,  alphabet, states, transitionFunction,initialState, finalState):
        self.alphabet = alphabet
        self.states = states
        self.transitionFunction = transitionFunction
        self.initialState = initialState
        self.finalState = finalState

    def run(self, string):
        __primitiveTypes = ["int", "char", "bool", "float", "double"]

        __I = [
            "a","b","c","d","e","f","g",'h',"i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
            "A","B","C","D","E","F","G",'H',"I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
            "_"
        ]

        __M = [
            "a","b","c","d","e","f","g",'h',"i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
            "A","B","C","D","E","F","G",'H',"I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
            "_","0","1","2","3","4","5","6","7","8","9"
        ]

        string

{
    "q0": {[]: ""},
    "q1": {},
    "q2": {}
}
