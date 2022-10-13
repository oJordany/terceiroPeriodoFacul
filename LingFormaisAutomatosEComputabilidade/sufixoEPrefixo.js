let palavra = "abccba"
let prefixo = ""
let prefixos = []
let sufixo = ""
let sufixos = []
for (letra of palavra){
    prefixo+=letra
    // console.log(prefixo)
    prefixos.push(prefixo)
}
for (let i = palavra.length - 1; i >= 0; i--){
    sufixo+=palavra[i]
    // console.log(sufixo)
    sufixos.push(sufixo)
}
console.log(`prefixos: {ε,${prefixos}} | sufixos: {ε,${sufixos}}`)