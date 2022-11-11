"""
    PROTOCOLO: padronização do envio e recebimento de informação 

    HTTP: HyperText Transfer Protocol
          » Define o modo como sites são acessados na internet
          » REquisição → Resposta

    RESPOSTAS DE REQUISIÇÕES: Strigs padronizadas
                              » Código de status
                              » Cabeçalho 
                              » Conteúdo

    MÉTODOS: » GET: Solicita um recurso para o servidor (uma página da web, por exemplo) e só retorna dados
             » POST: Enviamos uma informação para o servidor (submeter uma quantidade a um recurso específico)
             » HEAD: solicita uma resposta de forma idêntica ao método GET, porém sem conter o corpo da resposta
             » PUT: substitui todas as atuais representações do recurso de destino pela carga de dados de requisição
             » DELETE: remove um recurso específico
             » CONNECT: estabelece um túnel para o servidor indentificado pelo recurso de destino 
             » OPTIONS: usado para descrever opções de comunicação com o recurso de destino 
             » TRACE: executa um teste de chamada loop-back junto com o caminho par ao recurso de destino 
             » PATCH: utilizado para aplicar modificações parciais em um recurso

    CÓDIGO DE STATUS:   +--------------------------+---------------------------------------------------------------------------+
                        |Família                   |                                      Descrição                            |
                        +--------------------------+---------------------------------------------------------------------------+
                        |Informativo (1XX)         |    Respostas sem conteúdo, contendo apenas informações sobre a comunização|
                        |SUcesso (2XX)             |    A mensagem chegou ao servidor e era válida                             |
                        |Redirecionamento (3XX)    |    O recurso buscado está em outro servidor                               |
                        |Erro de cliente (4XX)     |    A requisição possui algum erro                                         |
                        |Erro do servidor (5XX)    |    O servidor não pode atender à requisição                               |
                        +--------------------------+---------------------------------------------------------------------------+
""" 

import requests

response = requests.get("https://g1.globo.com/")

print(f'status code: {response.status_code}')
print(f'↓ ↓ header ↓ ↓ \n {response.headers}')
print(f'↓ ↓ content ↓ ↓ \n {response.content}')