# Tradutor Dirigido por Sintaxe Simples

Tradutor simples que traduz expressões de adição e subtração com números de um dígito da notação infixa para a notação posfixa.

Esta é uma implementação em C de um tradutor dirigido por sintaxe apresentado no *Livro do Dragão*, no Capítulo 2.

O tradutor não possui analisador léxico, pois o mesmo só é útil quando a entrada contém lexemas de múltiplos caracteres.

> **Nota:** O tradutor não trata espaços em branco nem quebra de linha

## Esquema de tradução

O código foi escrito com base no esquema de tradução abaixo:

```
expr    ->  term rest

rest    ->  + term { print('+') } rest
        |   - term { print('-') } rest
        |   EPSILON

term    ->  0 { print('0') }
        |   1 { print('1') }
        |   2 { print('2') }
        |   3 { print('3') }
        |   4 { print('4') }
        |   5 { print('5') }
        |   6 { print('6') }
        |   7 { print('7') }
        |   8 { print('8') }
        |   9 { print('9') }
```

## Instalação

### Pré-Requisitos

 - Um compilador C (GCC ou Clang)
 - glibc
 - make
 - linux

> **Nota:** Esse programa foi testado somente em Linux!

### Como compilar

```bash
$ git clone https://github.com/guimaraesfe1/syntax-directed-translator.git
$ cd syntax-directed-translator
$ make
$ ./main
```

### Exemplo

```bash
> 1+1-4+9
11+4-9+
```
