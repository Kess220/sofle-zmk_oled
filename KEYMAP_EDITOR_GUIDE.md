# 🌐 Guia: Troca de Idioma no Keymap Editor Visual

## 🎯 **Sites do Keymap Editor:**

1. **ZMK Studio** (Oficial): https://zmk.studio/ 
2. **Keymap Editor** (Community): https://nickcoutsos.github.io/keymap-editor/
3. **Keymap Drawer**: https://keymap-drawer.streamlit.app/

---

## 🚀 **Passo a Passo - Keymap Editor:**

### **1. Acessar e Conectar:**
```
🔗 https://nickcoutsos.github.io/keymap-editor/

1. Clique "Enable GitHub Integration"
2. Autorize acesso ao seu repositório sofle-zmk_oled
3. Selecione seu repositório na lista
```

### **2. Localizar seu Sofle:**
```
1. Teclado: Procure por "Sofle" na lista
2. Lado: Left/Right (esquerdo/direito)
3. Carregar: Keymap atual aparecerá visualmente
```

---

## ⚡ **MÉTODO 1: Macro para Trocar Layout do Sistema**

### **3. Criar Macro de Troca:**
```
1. Vá em "Macros" (aba lateral)
2. Clique "Add Macro" 
3. Nome: "Layout_Toggle"
4. Ações:
   - macOS: Cmd + Space
   - Windows: Win + Space  
   - Linux: Alt + Shift
```

**Configuração da Macro:**
```
Macro: Layout_Toggle
├─ Press: LG (Left GUI/Cmd)
├─ Press: SPACE  
├─ Release: SPACE
└─ Release: LG
```

### **4. Atribuir a uma Tecla:**
```
1. Clique na tecla desejada (ex: encoder direito)
2. Selecione "Macro"
3. Escolha "Layout_Toggle"
4. Salvar
```

---

## 🎯 **MÉTODO 2: Layer Dedicada (Mais Avançado)**

### **5. Criar Layer "PT-BR":**
```
1. Clique "Add Layer" 
2. Nome: "Portuguese"
3. Configure teclas específicas:
   - Posição do P: &kp LBKT (acento agudo ´)
   - Posição do ;: &kp SEMI (ç quando configurado)
```

### **6. Tecla de Ativação:**
```
1. Escolha uma tecla (ex: Caps Lock)
2. Selecione "Toggle Layer" 
3. Escolha layer "Portuguese"
4. Resultado: Liga/desliga layer brasileiro
```

---

## 🎨 **Interface Visual do Editor:**

```
┌─────────────────────────────────────────────────────────────┐
│  🖥️  Keymap Editor                    🔗 GitHub Connected    │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌─────┬─────┬─────┬─────┬─────┬─────┐                     │
│  │  `  │  1  │  2  │  3  │  4  │  5  │   ← Clique para     │
│  ├─────┼─────┼─────┼─────┼─────┼─────┤     configurar      │
│  │ ESC │  Q  │  W  │  E  │  R  │  T  │                     │
│  └─────┴─────┴─────┴─────┴─────┴─────┘                     │
│                                                             │
│  Layers: [BASE] [LOWER] [RAISE] [+ADD]                     │
│  Macros: [Layout_Toggle] [Print_Screen] [+ADD]             │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🛠️ **Configuração Recomendada:**

### **Posição da Macro:**
```
Opção 1: Encoder direito (pressionar)
Opção 2: ADJUST layer + uma tecla específica  
Opção 3: Combo de teclas (ex: Q + P simultaneamente)
```

### **Macro Completa (macOS):**
```json
{
  "name": "layout_toggle",
  "bindings": [
    "&kp LG(SPACE)"
  ]
}
```

---

## 🎯 **Vantagens do Editor Visual:**

✅ **Interface gráfica** - vê exatamente onde cada tecla fica  
✅ **Macros visuais** - arrasta e solta ações  
✅ **Preview em tempo real** - testa antes de compilar  
✅ **Auto-sync GitHub** - compila automaticamente  
✅ **Backup automático** - nunca perde configuração  

---

## 📱 **Como Usar:**

### **Workflow Ideal:**
```
1. 🔧 PROGRAMANDO → Layout US ativo
2. 💬 CONVERSANDO → Pressiona tecla macro → Layout PT-BR  
3. 🔧 VOLTANDO A PROGRAMAR → Pressiona macro novamente → Layout US
```

### **Resultado:**
- ✅ **Uma tecla física** troca todo o sistema
- ✅ **Funciona com qualquer aplicativo** 
- ✅ **Zero configuração adicional** no OS
- ✅ **Instantâneo** - 1 segundo para trocar

---

## 🎊 **Próximos Passos:**

1. **Acesse**: https://nickcoutsos.github.io/keymap-editor/
2. **Conecte** seu GitHub
3. **Crie a macro** Layout_Toggle  
4. **Atribua a uma tecla** conveniente
5. **Salve** - compila automaticamente!
6. **Flash** o novo firmware
7. **Teste** a troca instantânea!

**Muito mais simples que editar código, né?** 🚀

