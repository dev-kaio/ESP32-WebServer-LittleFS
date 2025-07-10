Este projeto usa uma ESP32 que, por meio de um WebServer, permite ligar/desligar leds. O diferencial do projeto é o uso da biblioteca "litteFS", que permite organizar arquivos (html, por exemplo) fora do código principal (main.cpp).

Os arquivos ficam armazenados na pasta "data", que posteriormente é requisitada na main:

<img width="568" height="172" alt="image" src="https://github.com/user-attachments/assets/0dc71c21-086b-4ffd-a002-9766ac0cf731" />

Como foi feito:

Primeiramente criei um novo projeto no PlatformIO (extensão do VSCode que permite embarcar códigos para microcontroladores)

<img width="1213" height="388" alt="image" src="https://github.com/user-attachments/assets/b09ba0a3-0032-4aed-b525-e5f4c6800057" />

Em seguida fiz o código que seria embarcado (main.cpp), inclui as bibliotecas necessárias e fiz as devidas alterações no arquivo "platformio.ini":

<img width="548" height="115" alt="image" src="https://github.com/user-attachments/assets/058a8399-9f14-4a29-b189-7a4bd4830b3e" />

