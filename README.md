# VetorDinamico
Atividade avaliativa sobre Vetor Dinâmico da matéria de algoritmos

Arquivos base para implementação de classes de 
vetor dinâmico em C++. 
Cada classe esta definida no arquivo 'classe.hpp'. 
São 2 classes: 'array_list' e 'linked_list', 
cada uma definida no respecivo arquivo, 
'array_list.hpp' e 'linked_list.cpp'.

São fornecidos arquivos de teste básicos. Cada arquivo de 
teste começa com a palavra 'test', seguida das informações 
do que é testado por este arquivo. O programa mostra
na saída de erro o tempo total necessário para realizar o teste 
a que se propõe.

Exemplo de como compilar o arquivo de teste de push_front em um
'linked_list':
  g++ -Wall -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp 

Para executar:
  ./test-pushfront-linked-list-01 < tests/push/e1.txt

São fornecidos 5 arquivos de base para o programa de teste 
de inserção: e1.txt, e2.txt, e3.txt , e4.txt e e5.txt, 
no diretório 'tests/push/'. 
A primeira  linha de cada  arquivo contém um inteiro `n` 
com a quantidade  total de números do arquivo. 
Depois o arquivo contém `n` linhas, cada uma com um 
número inteiro.
Estes arquivos contém uma sequencia de números gerados de forma
aleatória através do programa `gen_array.cpp`. 

Para compilar o programa gen_array.c: 
  g++ -Wall -o gen_array gen_array.cpp

O programa `gen_array` recebe um valor inteiro `n`
como parâmetro e gera um arquivo com `n` números 
gerados de forma aleatória. Para gerar um arquivo 
com nome `meu_teste.txt`, com 1000 números inteiros:
  ./gen_array 1000 > meu_teste.txt 

O arquivo gerado `meu_teste.txt` terá n+1 linhas, 
a primeira com o valor 1000 e a 1000 com 
1 valor inteiro cada, gerados aleatoriamente. 

Existem dois arquivo de teste de 'remove_at', no diretório 
'tests/remove_at/': e1.txt e e2.txt. Cada arquivo insere 15 elementos 
e depois remove '10' elementos pelo índice. No arquivo 'e1.txt' 
é garantido que todos os '10' elementos a serem removidos são removidos, 
enquanto que o no arquivo 'e2.txt', apenas '8' dos '10' são removidos.

Exemplo de como compilar o arquivo de teste do remove_at em um
'array_list':
  g++ -Wall -o test-removeat-array-list-01 test-removeat-array-list-01.cpp 

Para executar:
  ./test-removeat-array-list-01 < tests/remove_at/e1.txt