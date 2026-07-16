# Introdução

Para ter um bom entendimento da plataforma ZMK e tudo o que ela pode oferecer é interessante ler a documentação completa no site do [ZMK](https://zmk.dev/docs/user-setup).

Lá tem a documentação para os teclados mais utilizados como Sofle, Lily58, Corne, etc...

---

## Pré requisitos

Para prosseguir com a personalização e instalação do seu teclado sugerimos que faça o fork deste repositório

---

## Configuração

É possível realizar a instalação e configuração do seu teclado por dois caminhos:

1. [Configuração manual](#configuração-manual)
2. [Configuração visual](#configuração-visual)


### Configuração manual

![image](https://github.com/user-attachments/assets/07776e9f-de8b-4a12-ba79-470632582f6d)

Para a configuração manual sugerimos que siga os seguintes passos:

1. Primeiro passo é forkar a config setup do ZMK, no user-setup -> https://zmk.dev/docs/user-setup
2. Escolher a board do seu teclado, que na maioria das vezes será **Board:Nicenano V2**
3. Copiar o layout base/default para o github.

![image](https://github.com/user-attachments/assets/0527c640-3f06-4531-b0c0-1f64584daef7)

É importante fazer essa configuração inicial, para que então você consiga alterar o keymap da melhor forma.

![image](https://github.com/user-attachments/assets/3cc4374a-771b-4393-8859-d5db8fbc1b11)

Para fazer as alterações pelo github, é só alterar e criar regras no [teclado].keymap de acordo com o que você, o USER, achar melhor.
Atenção! Considere alterar direto pelo arquivo `[teclado].keymap` quando você já leu as docs do zmk e sabe exatamente o que está fazendo! Aqui, nunca vai ter algum tipo de limitação por GUI, apenas limitação pelo seu próprio código.

## Instalação

Para flashear o firmware do teclado novo basta seguir os seguintes passos:

1. Conectar o cabo USB
2. Dar dois cliques no botão de RST do teclado em menos de 1s

![telegram-cloud-photo-size-1-5040021887542996513-y](https://github.com/user-attachments/assets/217fe770-6b37-4470-a5f0-d6640a593a94)

Feito isso, uma pasta igual um pendrive irá aparecer com o nome de "Nicenano".
Basta copiar o arquivo LEFT para o teclado esquerdo e copiar o arquivo RIGHT no teclado direito.

![image](https://github.com/user-attachments/assets/fec189f3-8293-4407-89ad-9f4268b701dc)

Nunca é preciso apagar nenhum arquivo dentro do Nicenano ( ou outra MCU ), sempre que atualizar só é necessário jogar um arquivo novo.

| É comum que apareça um erro após após passar o novo firmware pra o teclado. Fiquem tranquilos não é um bug, é um feature do zmk : )


### Configuração visual

#### RECOMENDADA: Através do [KeymapEditor](https://nickcoutsos.github.io/keymap-editor/)

![image](https://github.com/user-attachments/assets/1bffa913-4f2e-4369-be6f-9c86814e70db)

Este é de longe o que mais recomendamos para quem está iniciando. Uma GUI sem limitações, onde você pode configurar de tudo e ainda aprender enquanto configura. Lá você tem acesso a funções como tap dance, behaviors, conditional layers, macro, combos, layers infinitas e etc.

O Keymap Editor é especial porque basicamente automatiza as alterações que foram feitas na GUI de volta para o github e também builda o actions automaticamente.

Para utilizar o KeymapEditor basta você logar com a sua conta GitHub e vincular o fork deste repositório.

Assim que você realizar suas alterações basta clicar em "Save" no canto superior esquerdo que irá enviar as alteraçõees para o github e acionará uma pipeline para buildar o projeto. Assim que o build finalizar um Artefato chamado `firmeware.zip` ficará disponível para download.

![image](https://github.com/user-attachments/assets/c7c339a6-d595-4469-b02d-d556a2a272ed)

Veja a seção [Instalação](#instalação) para prosseguir com a instalação do seu firmeware

---

#### ZMK STUDIO

Esse é a GUI mais nova do ZMK, ainda está em Beta, tem algumas limtações, não gosto de recomendar pois não salva as configs do ZMK direto no github, além de não ter algumas configurações de tap dance e behaviors.

![image](https://github.com/user-attachments/assets/f1532b9f-3dba-42ea-84fa-412ed3341d09)

A vantagem do ZMK.STUDIO é que você quase nunca precisará mexer em código, compilar, baixar e passar o novo firmware de cada alteração para o teclado, o que pode definitivamente ser chato. Mas, não acho que vale a pena, ao menos quando você ainda está aprendendo a usar o ZMK.

---

## Layout deste build

Uso split (`nice_nano_v2`, OLED, sem RGB) pra trabalho (Scala/Spark/Databricks, macOS) e jogos (Windows). Camadas atuais:

- **BASE** — QWERTY padrão.
- **LOWER** — F-keys, símbolos, controles de mídia (prev/play-pause/next), toggle da GAMER.
- **RAISE** — seleção de perfil Bluetooth (`BT_CLR`/`BT_SEL 0-4`), navegação (setas + HOME/END/PGUP/PGDN), clipboard (Ctrl+A/Z/X/C/V + Redo `Ctrl+Shift+Z`), e troca de canal de saída (`OUT_USB`/`OUT_BLE`, ver seção abaixo).
- **ADJUST** (`LOWER`+`RAISE` seguradas) — mouse emulation: scroll em Y/H, click em U/O, movimento em I/J/K/L. Segurar **T** dentro da ADJUST ativa velocidade turbo (`TURBO_MOUSE`) nessas mesmas teclas de movimento.
- **GAMER** — troca Space/Enter de posição pra FPS; ativa via combo **F+J** ou pela tecla dedicada no canto superior esquerdo da LOWER. As demais teclas caem (`&trans`) pra BASE, então LOWER/RAISE continuam acessíveis normalmente dentro da GAMER.

### Trocar entre USB e Bluetooth sem tirar o cabo

Por padrão o ZMK muda pra saída USB assim que detecta o cabo conectado. Se você quiser usar o cabo **só pra carregar** e continuar indo por Bluetooth pra outro dispositivo:

- `RAISE` + tecla **6** (linha numérica) → `&out OUT_USB` (força saída via cabo)
- `RAISE` + tecla **7** (linha numérica) → `&out OUT_BLE` (força saída via BLE, mesmo com o cabo plugado)

Depois é só usar o `BT_SEL 0-4` (mesma camada) pra escolher o dispositivo pareado.

### Energia

- `CONFIG_ZMK_DISPLAY_BLANK_ON_IDLE` — apaga o render do OLED no idle (economia leve, cotidiana).
- `CONFIG_ZMK_SLEEP` + `CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=600000` — deep sleep de verdade (corta CPU/rádio) após 10min parado. Acorda no primeiro key press.
- `CONFIG_ZMK_BLE_EXPERIMENTAL_CONN` está desligado no central — foi um teste pra um problema de reconexão lenta/desconexão aleatória no Windows via adaptador USB de Bluetooth. Se o board voltar a ter esse problema mesmo com o ajuste de energia USB do Windows feito, essa é a próxima flag a investigar.

---

