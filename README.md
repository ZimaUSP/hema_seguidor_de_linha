# Hemabot Line Follower

## Descrição do Projeto

O **Hemabot Line Follower** é um robô móvel autônomo projetado para realizar **entregas automatizadas em ambientes hospitalares**, com foco no **transporte seguro de amostras sanguíneas entre setores clínicos**.

O sistema utiliza **seguimento de linha no solo** como método de navegação principal, permitindo deslocamento confiável em rotas pré-definidas dentro de laboratórios, corredores ou centros médicos.

Como demonstração funcional, o robô executa uma **trajetória em formato de L**, simulando o deslocamento entre dois pontos de coleta e análise.

O projeto busca demonstrar como soluções de **robótica móvel simples podem contribuir para automação hospitalar**, reduzindo o tempo de transporte de amostras e minimizando intervenções humanas em tarefas repetitivas.

---

## Objetivos

* Desenvolver um **robô autônomo seguidor de linha**
* Simular um **sistema de entrega hospitalar**
* Transportar **amostras sanguíneas entre dois pontos**
* Implementar **navegação simples baseada em sensores**
* Demonstrar um **protótipo funcional de robótica aplicada à saúde**

---

## Funcionamento

O Hemabot opera seguindo uma **linha marcada no chão**, utilizando sensores infravermelhos para identificar a trajetória.

Durante o deslocamento:

1. Os **sensores infravermelhos** detectam a linha no solo.
2. O sistema de controle ajusta os motores para manter o robô alinhado com a trajetória.
3. O robô percorre uma **rota em formato de L** até chegar ao destino.
4. Sensores de distância auxiliam na **detecção de obstáculos ou proximidade de objetos**.

---

## Sensores Utilizados

### Sensores Infravermelhos (IR)

Responsáveis por detectar a linha no chão e permitir o **seguimento de trajetória**.

Funções principais:

* Identificação da linha
* Correção de trajetória
* Controle de direção

---

### Sensor de Distância

Utilizado para **detecção de obstáculos ou aproximação de objetos**, contribuindo para maior segurança na navegação.

Funções principais:

* Identificar obstáculos
* Evitar colisões
* Monitorar proximidade

---

## Arquitetura do Sistema

O sistema do robô é composto por:

* **Controlador principal** (microcontrolador ou FPGA)
* **Sensores infravermelhos** para seguimento de linha
* **Sensor de distância**
* **Motores de tração**
* **Estrutura mecânica do robô**
* **Compartimento para transporte de amostras**

---

## Aplicação Hospitalar

Em ambientes hospitalares, o transporte de materiais biológicos é uma tarefa frequente e sensível.

O Hemabot demonstra um conceito de robô capaz de:

* Transportar **amostras sanguíneas**
* Circular entre **salas de coleta e laboratórios**
* Reduzir **tempo de deslocamento manual**
* Minimizar **contaminação e manipulação humana**

---

