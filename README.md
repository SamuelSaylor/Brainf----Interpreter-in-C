<table><tr>
<td><img src="./30projects_logo.svg" width="360"/></td>
<td><h1>Day 1/30 — Brainf### Interpreter</h1></td>
</tr></table>

Yes, you read the title properly. "Brainfuck" is a Turing-complete programming language with only eight characters that can be used in the language. It mimicks the low-level operations of a Turing Machine. The language itself isn't practical in use, but it is a fun way to understand computer logic as well as being an enjoyable challenge for your everyday programming. The language is comprived of a "tape", a one dimensional array with all data being utilized, and your programming instructions, which controls a pointer to determine to do with each cell. You'll find a table with ALL SYNTAX below!

This is actually my first project written in C, and technically the first time I've ever finished creating an Interpreter (as I have some incomplete ones in the drafts). From what I've done so far, C is Java if Java was actually fun to use.

| Symbol | Action |
|--------|--------|
| `>` | Move pointer right |
| `<` | Move pointer left |
| `+` | Increment current cell |
| `-` | Decrement current cell |
| `.` | Output current cell as ASCII |
| `,` | Read one byte of input into current cell |
| `[` | Jump to matching `]` if current cell is 0 |
| `]` | Jump back to matching `[` if current cell is nonzero |

Below is an example of printing "Hello world!" in the language:

```++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<<<-]<-]>>.>>+.+++++++..+++.<<++.>------------.<<.+++.------.--------.>+.>.```
