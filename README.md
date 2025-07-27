# Pascal to C Compiler

An academic compiler project that translates Pascal source code to C, implementing fundamental compiler design principles including lexical analysis, syntax parsing, and code generation with comprehensive error handling.

## 🚀 Features

### 🔧 Core Compiler Components
- **Lexical Analysis with Flex**: Tokenization of Pascal source code
- **Syntax Parsing with Bison**: Grammar-based parsing and syntax tree generation
- **Symbol Table Management**: Variable and function scope handling
- **Error Detection and Reporting**: Comprehensive error messages with line numbers
- **Code Generation**: Translation from Pascal constructs to equivalent C code

### 📚 Language Support
- **Pascal Language Features**: Variables, functions, procedures, control structures
- **Data Types**: Integer, real, boolean, char, arrays, records
- **Control Structures**: If-then-else, while loops, for loops, case statements
- **Procedures & Functions**: Parameter passing, local variables, recursion
- **Advanced Features**: Nested scopes, type checking, semantic analysis

## 🛠️ Technologies Used

- **C Programming Language**: Core compiler implementation
- **Flex (Fast Lexical Analyzer)**: Lexical analysis and tokenization
- **Bison (GNU Parser Generator)**: Syntax analysis and parsing
- **Compiler Design Principles**: Formal language theory and automata
- **Data Structures**: Hash tables, symbol tables, abstract syntax trees
- **Unix/Linux Tools**: Make, GCC, debugging tools

## 📁 Project Structure

```
Compilador_Pascal_a_C/
├── scanner_final.l      # Flex lexical analyzer specification
├── sintactico.y        # Bison grammar specification
├── hash.c              # Hash table implementation for symbol table
├── hash.h              # Hash table header file
├── lex.yy.c           # Generated lexical analyzer
├── sintactico.tab.c   # Generated parser
├── sintactico.tab.h   # Parser header file
├── Arbol_binario.cpp  # Binary tree implementation
├── CodigoPruebas/     # Test Pascal programs
├── Codigo_apoyo/      # Supporting code and utilities
├── Compila_Flex/      # Flex compilation scripts
├── Compila_Todo/      # Complete build scripts
├── Pila/              # Stack implementation
├── Automata.png       # Finite automata diagram
├── Gramática.docx     # Grammar specification document
└── README.md          # This file
```

## 🔧 Installation & Compilation

### Prerequisites
- GCC compiler
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Unix/Linux environment (or Windows with appropriate tools)

### Compilation Steps
```bash
# Clone the repository
git clone https://github.com/gonthegeek/Compilador_Pascal_a_C.git
cd Compilador_Pascal_a_C

# Compile the lexical analyzer
flex scanner_final.l

# Compile the parser
bison -d sintactico.y

# Compile the complete compiler
gcc -o pascal_compiler lex.yy.c sintactico.tab.c hash.c -lfl
```

### Using the Compiler
```bash
# Compile a Pascal program to C
./pascal_compiler input.pas output.c

# Test with sample programs
./pascal_compiler CodigoPruebas/ejemplo1.pas resultado.c
```

## 🎯 Compiler Phases

### 1. Lexical Analysis (Scanner)
- **Token Recognition**: Identifies keywords, identifiers, operators, literals
- **Pattern Matching**: Uses regular expressions for token classification
- **Error Handling**: Reports lexical errors with position information

### 2. Syntax Analysis (Parser)
- **Grammar Processing**: Context-free grammar for Pascal language
- **Parse Tree Generation**: Builds abstract syntax tree
- **Syntax Error Recovery**: Attempts to continue parsing after errors

### 3. Semantic Analysis
- **Type Checking**: Ensures type compatibility in expressions
- **Scope Resolution**: Manages variable and function scopes
- **Declaration Checking**: Verifies all identifiers are declared before use

### 4. Code Generation
- **C Code Output**: Generates equivalent C source code
- **Optimization**: Basic optimizations for generated code
- **Runtime Support**: Handles Pascal-specific constructs in C

## 🔍 Example Translation

### Pascal Input:
```pascal
program ejemplo;
var
    x, y: integer;
    suma: integer;
begin
    x := 10;
    y := 20;
    suma := x + y;
    writeln('La suma es: ', suma);
end.
```

### Generated C Output:
```c
#include <stdio.h>

int main() {
    int x, y;
    int suma;
    
    x = 10;
    y = 20;
    suma = x + y;
    printf("La suma es: %d\n", suma);
    
    return 0;
}
```

## 📊 Supported Pascal Features

- ✅ **Basic Data Types**: integer, real, boolean, char
- ✅ **Variables**: Declaration and assignment
- ✅ **Arithmetic Operations**: +, -, *, /, div, mod
- ✅ **Comparison Operations**: =, <>, <, >, <=, >=
- ✅ **Logical Operations**: and, or, not
- ✅ **Control Structures**: if-then-else, while, for, repeat-until
- ✅ **Procedures and Functions**: Declaration and calls
- ✅ **Arrays**: One-dimensional array support
- ✅ **Input/Output**: read, readln, write, writeln

## 🌟 Academic Learning Outcomes

This project demonstrates understanding of:
- **Compiler Design Theory**: Formal language principles and compiler phases
- **Automata Theory**: Finite state machines and context-free grammars
- **Data Structures**: Symbol tables, hash tables, trees, stacks
- **Systems Programming**: Low-level programming and tool integration
- **Software Engineering**: Large project organization and testing

## 🧪 Testing

The project includes comprehensive test cases:
```bash
# Run test suite
cd CodigoPruebas
../pascal_compiler test1.pas test1.c
../pascal_compiler test2.pas test2.c
# Verify generated C code compiles and runs correctly
```

## 📚 Documentation

- **Grammar Specification**: See `Gramática.docx` for complete language grammar
- **Automata Diagrams**: Visual representation in `Automata.png`
- **Code Examples**: Various test cases in `CodigoPruebas/` directory

## 🏆 Key Achievements

- **Complete Compiler Pipeline**: Full translation from Pascal to C
- **Robust Error Handling**: Comprehensive error detection and reporting
- **Academic Excellence**: Demonstrates deep CS fundamentals knowledge
- **Production-Quality Code**: Well-structured, maintainable implementation

## 📄 License

Academic License - Created for educational purposes and learning.

---

**Developed by Gonzalo Ronzon** | [Portfolio](https://gonzaloronzon.com) | [LinkedIn](https://linkedin.com/in/gonzalo-ronzon)
