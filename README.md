Este projeto usa uma ESP32 que, por meio de um WebServer, permite ligar/desligar leds. O diferencial do projeto é o uso da biblioteca "LittleFS", que permite organizar arquivos (html, por exemplo) fora do código principal (main.cpp).

Os arquivos ficam armazenados na pasta "data", que posteriormente tem seus arquivos requisitados no código principal:

<img width="568" height="172" alt="image" src="https://github.com/user-attachments/assets/0dc71c21-086b-4ffd-a002-9766ac0cf731" />

COMO FOI FEITO:

Primeiramente criei um novo projeto no PlatformIO (extensão do VSCode que permite embarcar códigos para microcontroladores)

<img width="1213" height="388" alt="image" src="https://github.com/user-attachments/assets/b09ba0a3-0032-4aed-b525-e5f4c6800057" />

Em seguida fiz o código que seria embarcado (main.cpp), inclui as bibliotecas necessárias e fiz as devidas alterações no arquivo "platformio.ini":

<img width="548" height="115" alt="image" src="https://github.com/user-attachments/assets/058a8399-9f14-4a29-b189-7a4bd4830b3e" />
(platformio.ini)

<img width="180" height="87" alt="image" src="https://github.com/user-attachments/assets/92f412ba-b2a1-4c74-b46c-7c10ec568bab" />
(bibliotecas em "main.cpp").

Na função "setup" do código principal é preciso chamar a biblioteca para que ela monte o sistema de arquivos e dizer qual será a rota principal que ela deve seguir (o uso de rotas 
se deve por conta da biblioteca "WebServer"):
<img width="296" height="160" alt="image" src="https://github.com/user-attachments/assets/80dd2cf6-987d-4b19-8390-f572c6f20635" />

Para que a biblioteca funcione corretamente é necessário usar um comando no terminal:
pio run --target uploadfs

Esse comando compila e faz o upload do sistema de arquivos (como o index.html) para a memória flash da ESP32, usando o gerenciador de arquivos definido no projeto (neste caso, LittleFS).
É necessário rodar esse comando sempre que alterar ou adicionar arquivos na pasta /data, sempre que formatar o sistema de arquivos e sempre que a ESP32 não conseguir montar o LittleFS.

Com isso, a biblioteca funcionará corretamente.

