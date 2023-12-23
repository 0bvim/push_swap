![push_swap](../../../42-project-badges/blob/main/covers/cover-push_swap-bonus.png)

[![eng](../../../stuff/blob/main/USA-icon.png)](README.md) [![pt-BR](../../../stuff/blob/main/Brazil-icon.png)](README.pt-BR.md)

# push_swap
>Este projeto fará com que você classifique os dados em uma pilha, com um conjunto limitado de instruções, usando
o menor número possível de ações. Para ter sucesso, você terá que manipular vários
tipos de algoritmos e escolher a solução mais apropriada (entre muitas) para um
classificação otimizada de dados.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | troca os primeiro elemento com o segundo da stack A |
| sb            | troca os primeiro elemento com o segundo da stack B |
| ss            | executa o comando sa e o sb ao mesmo tempo |
| pa            | remove o primeiro elemento da stack B and puts it on top of A |
| pb            | remove o primeiro elemento da stack A and puts it on top of B |
| ra            | rotaciona a stack A de cima para baixo |
| rb            | rotaciona a stack B de cima para baixo |
| rr            | rotaciona ambas stacks A e B de cima para baixo |
| rra           | rotaciona a stack A de baixo para cima |
| rrb           | rotaciona a stack B de baixo para cima |
| rrr           | rotaciona ambas stacks A e B de baixo para cima |

## Parte mandatoria
Ordenar uma lista de numeros.

>a saida e a sequencia de movimentos para ordenar a lista
```bash
$ ./push_swap 5 3 4 1 2
$ rra
$ rra
$ pb
$ pb
$ ra
$ pa
$ pa
#sendo assim, apos esses movimento a lista estara ordenada " 1 2 3 4 5 "
```
#
>todas as entradas a seguir devem retornar `Error`
```bash
$ ./push_swap 5 3 4 1 a2
$ ./push_swap a b c
$ ./push_swap 5 2 3 1 2
$ ./push_swap --2 3 5 1
$ ./push_swap -2- 3 7 9
```
> :bulb: **Dica:** Realize mais testes e validaçoes com entradas diferentes

### Descrição da parte de bônus
Precisamos criar um programa chamado 'verificador'. Esse programa verifica se a lista de instruções gerada pelo programa push_swap esta realmente ordenada.
```bash
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK # exibe 'OK' se a lista foi organizada corretamente.

$>./checker 3 2 1 0
sa
rra
pb
KO # exibe 'KO' se a lista nao foi organizada.

$>./checker 3 2 one 0
Error # quando argumentos diferentes de numeros.

$>./checker "" 1
Error # quando tem uma string vazia ou quando nao ha argumentos invalidos!
```
Use `make` or `make bonus` and follow instructions [`Here`](#discription-of-mandatory-part)

## Download
### ssh
```ssh
git clone git@github.com:vinicius-f-pereira/push_swap.git
```
### https
```bash
git clone https://github.com/vinicius-f-pereira/push_swap.git
```
### github cli (gh)
```bash
gh repo clone vinicius-f-pereira/push_swap
```

