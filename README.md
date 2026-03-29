# Benchmark de Performance: C, C++, Go e Rust

## Resumo

Este projeto compara 4 linguagens executando o mesmo fluxo:

1. Criar um vetor com capacidade inicial de 20.000.000 elementos.
2. Preencher com valores crescentes de 0 ate 19.999.999.
3. Preencher novamente com valores decrescentes de 20.000.000 ate 1.
4. Medir o tempo total do processo em milissegundos.

Observacao: no fim da execucao, cada codigo usa uma estrategia simples para evitar que o compilador remova o trabalho feito por otimizacao agressiva.

## O que foi feito em cada linguagem

- C: alocacao manual com `malloc`, preenchimento em duas fases, tempo com `QueryPerformanceCounter`.
- C++: uso de `std::vector`, preenchimento em duas fases, tempo com `std::chrono`.
- Go: uso de slice com `make`, preenchimento em duas fases, tempo com `time.Now` e `time.Since`.
- Rust: uso de `Vec<u64>`, preenchimento em duas fases, tempo com `Instant`.

## Resultado dos testes (preencher)

Preencha os tempos abaixo com os valores dos seus consoles.

| Linguagem |      Comando usado     | Melhor tempo(ms) |
|------|-----------------------------|------------------|
| C    | .\\main.exe                 |     102.401      |
| C++  | .\\main.exe                 |     398.501      |
| Rust | rustc main.rs + .\\main.exe |     408.097      |
| Go   | go run main.go              |     99.242       |

## Ranking (preencher)

1. Go
2. C
3. C++
4. Rust

## Metodologia

- Sistema operacional: Windows
- CPU Ryzen 5600 
- Memória 32GB RAM DDR4 operando a 2400Mhz
- Entrada total inserida no vetor: 40.000.000 valores
- Medicao: tempo total da fase crescente + fase decrescente
- Unidade: milissegundos

## Como executar

### C

```powershell
cd C\output
.\main.exe
```

### C++

```powershell
cd C++\output
.\main.exe
```

### Rust

```powershell
cd Rust\src
rustc main.rs
.\main.exe
```

### Go

```powershell
cd GO
go run main.go
```

## Estrutura

```text
playing-go/
  C/main.c
  C/output/main.exe
  C++/main.cpp
  C++/output/main.exe
  GO/main.go
  Rust/src/main.rs
```

---

Documento atualizado em: 29/03/2026
