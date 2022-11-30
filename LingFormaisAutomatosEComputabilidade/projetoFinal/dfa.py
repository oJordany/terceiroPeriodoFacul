from dfa import DFA

dfa1 = DFA(
    start=0,
    inputs={0, 1},
    label=lambda s: (s % 4) == 3,
    transition=lambda s, c: (s + c) % 4,
)

dfa2 = DFA(
    start="left",
    inputs={"move right", "move left"},
    label=lambda s: s == "left",
    transition=lambda s, c: "left" if c == "move left" else "right",
)
