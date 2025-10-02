# Hangman Game in C

**[Mudar para Português (Switch to Portuguese)](#-jogo-da-forca-em-c)**

This is a simple Hangman game developed in the C language. It was created as a project for the Alura course *"C II: avançando na linguagem"* (C II: Advancing in the language).

## 🚀 Features

- **Classic Gameplay**: Guess the secret word letter by letter to save the stick figure.
- **ASCII Art**: Visual representation of the gallows and win/loss messages.
- **Dynamic Word List**: Words are loaded from an external file (`palavras.txt`).
- **Add New Words**: At the end of a match, you have the option to add a new word to the game's list.

## 📋 Prerequisites

To compile and run this project, you will need a C compiler, such as GCC.

## ⚙️ How to Compile and Run

1.  **Clone or download the repository files:** Make sure you have `forca.c`, `forca.h`, and `palavras.txt` in the same directory.

2.  **Compile the code:** Open your terminal and run the following command:
    ```sh
    gcc forca.c -o forca
    ```

3.  **Run the executable:**
    ```sh
    ./forca
    ```

## 룰 Rules

- All words are in **UPPERCASE**.
- Do not use accents (e.g., use `MELAO` instead of `MELÃO`).

## 📁 File Structure

The `palavras.txt` file is essential for the game to work. It must be structured as follows:
- The first line contains the total number of words in the file.
- The subsequent lines contain one word each.

**Example of `palavras.txt`:**
```sh
3
MELANCIA
BANANA
MORANGO
```

---

# 🇧🇷 Jogo da Forca em C

**[Switch to English (Mudar para Inglês)](#-hangman-game-in-c)**

Este é um simples Jogo da Forca desenvolvido em linguagem C. Foi criado como um projeto para o curso *"C II: avançando na linguagem"* da Alura.

## 🚀 Funcionalidades

- **Jogabilidade Clássica**: Adivinhe a palavra secreta letra por letra para salvar o boneco.
- **Arte ASCII**: Representação visual da forca e das mensagens de vitória/derrota.
- **Lista de Palavras Dinâmica**: As palavras são carregadas de um arquivo externo (`palavras.txt`).
- **Adicionar Novas Palavras**: Ao final de uma partida, você tem a opção de adicionar uma nova palavra à lista do jogo.

## 📋 Pré-requisitos

Para compilar e executar este projeto, você precisará de um compilador C, como o GCC.

## ⚙️ Como Compilar e Executar

1.  **Clone ou baixe os arquivos do repositório:** Certifique-se de que `forca.c`, `forca.h`, e `palavras.txt` estão no mesmo diretório.

2.  **Compile o código:** Abra seu terminal e execute o seguinte comando:
    ```sh
    gcc forca.c -o forca
    ```

3.  **Execute o programa:**
    ```sh
    ./forca
    ```

## 룰 Regras

- Todas as palavras estão em **LETRAS MAIÚSCULAS**.
- Não utilize acentos (ex: use `MELAO` em vez de `MELÃO`).

## 📁 Estrutura do Arquivo

O arquivo `palavras.txt` é essencial para o funcionamento do jogo. Ele deve ser estruturado da seguinte forma:
- A primeira linha contém o número total de palavras no arquivo.
- As linhas seguintes contêm uma palavra cada.

**Exemplo do `palavras.txt`:**
```sh
3
MELANCIA
BANANA
MORANGO
```
