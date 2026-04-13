Integrantes: Lucas Lauzid Dall'Agnol && José Arthur Serrão Moreira.

Objetivo do Projeto:
O propósito central deste desenvolvimento foi consolidar e validar os conhecimentos técnicos adquiridos em sala de aula. Mais do que apenas criar um produto final, o projeto serviu como um laboratório prático para aplicar os conceitos de programação explorados durante o curso. Ele demonstra nossa capacidade de traduzir requisitos acadêmicos em uma aplicação funcional, criativa e tecnicamente sólida.

Uso de inteligêngia artificial no desenvolvimento do projeto: 

Pergunta realizada pela dupla:

Como posso tornar a escolha do computador aleatória no meu código em C, existe uma função ou comando que execute essa tarefa? E como faço para aplica-lo?

Resposta obtida: 

Em C, a "aleatoriedade" não é pura (o computador segue uma fórmula matemática), por isso chamamos de números pseudoaleatórios.
Para fazer isso, você usará principalmente duas funções da biblioteca <stdlib.h> e uma da <time.h>.

1. As ferramentas necessárias:
rand(): Gera um número inteiro aleatório entre 0 e um valor máximo (geralmente 32767).
srand(): Define a "semente" (seed) para o gerador. Sem isso, o computador vai gerar sempre a mesma sequência de números toda vez que você abrir o programa.
time(NULL): Pega o horário atual do sistema. Como o tempo sempre muda, usamos isso para que a semente seja sempre diferente.

2. Observações relevantes:
Como o rand() gera números muito grandes, usamos o operador de resto (%) para "domar" esse valor:
De 0 a 10: rand() % 11
De 1 a 10: (rand() % 10) + 1
De 5 a 15: (rand() % 11) + 5
Dica de Ouro: Nunca esqueça o srand(time(NULL)). Se você esquecer, o computador pode até parecer aleatório na primeira vez, mas ele vai repetir exatamente as mesmas escolhas toda vez que você reiniciar o executável!
