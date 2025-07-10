Este projeto usa uma ESP32 que, por meio de um WebServer, permite ligar/desligar leds. O diferencial do projeto é o uso da biblioteca "litteFS", que permite organizar arquivos (html, por exemplo) fora do código principal (main.cpp).

Os arquivos ficam armazenados na pasta "data", que posteriormente é requisitada na main:

<img width="568" height="172" alt="image" src="https://github.com/user-attachments/assets/0dc71c21-086b-4ffd-a002-9766ac0cf731" />


