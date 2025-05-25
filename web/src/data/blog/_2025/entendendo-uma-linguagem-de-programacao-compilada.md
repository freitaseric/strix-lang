---
pubDatetime: 2025-05-24T20:40:03.000-04:00
modDatetime: 
title: Entendendo como funciona uma linguagem de programação compilada
featured: false
draft: false
tags:
  - PesquisaTecnica
description: Este é o início da pesquisa técnica para desenvolver o Strix.
---

Como funciona o processo de compilação de uma linguagem de programação?
Nesse *blog post* irei sanar esta dúvida.

## A forma mais rápida

Como primeira abordagem para entender mais sobre como criar uma linguagem de programação compilada, decidi perguntar a uma IA.
Escolhi utilizar o Google Gemini, já que, possuo a versão `Pro` do mesmo graças
a uma promoção do Google One exclusiva para usuários de email `.edu`.

Bem, compreendo que respostas de IAs não são necessáriamente confiáveis, entretanto
utilizei-a apenas como forma de criar um pequeno guia mental de por onde seguir.

O principal e primeiro ponto que foquei na resposta foi a arquitetura de um compilador,
de acordo com o Gemini (*2.5 Preview*), é necessário 3 fases principais para que
o mesmo funcione corretamente, sendo elas:
* Análise Léxica
* Análise Sintática
* Análise Semântica

A partir do momento que estive com essas informações, fui em busca de entender
como implementar de forma manual a primeira fase de um compilador, a análise léxica.
Assim, pedi ao Gemini links onde posso encontrar informações a respeito de como
fazer um analisador léxico.

> Link para a conversa com o Gemini: https://g.co/gemini/share/00d2f61bfb7a

## O verdadeiro começo

A primeira referência, dada pela IA, que decidi seguir foi a ["Crafiting Interpreters"
por Robert Nystrom](http://craftinginterpreters.com), o qual mostra como criar 
um interpretador simples usando a linguagem Java a qual eu tenho certa proeficiência,
portanto utilizei o artigo [Scanning](https://craftinginterpreters.com/scanning.html)
para entender a lógica por trás da primeira etapa de um compilador/interpretador.

Após uma extensa leitura da página, o conceito de um lexer se tornou mais claro
em minha mente, e o funcionamento do mesmo parece tão simples quanto um simples
`switch...case...`. Porém, sei que não é tão simples assim. Afinal, linguagens
mais robustas costumam ter centenas de linhas de código apenas para essa fase,
e inúmeras ferramentas com esse proprósito foram criadas para facilitar a vida
dos desenvolvedores de linguagens.

## A derrota ao cansaço

Após 4 horas seguidas de pesquisa finalmente me cansei, visto isso salvei todas
as guias do navegador no grupo de guias da Strix em meu navegador e decidi dormir.

Tudo indica que amanhã irei iniciar o dia implementando um lexer simples,
tão simples que será capaz, apenas, de *tokenizar* cálculos matemáticos ou qualquer
estrutura simples como esta.