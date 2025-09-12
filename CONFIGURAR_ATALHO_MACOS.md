# 🍎 Personalizar Atalho de Troca de Idioma - macOS

## 🎯 **Configuração Rápida:**

### **1. Acessar Configurações:**
```
🍎 Menu Apple → Configurações do Sistema → Teclado
```

### **2. Ir para Atalhos:**
```
Teclado → Atalhos de Teclado → Fontes de Entrada
```

### **3. Configurar Atalhos:**
```
✅ Marque: "Selecionar a próxima fonte de entrada"
✅ Marque: "Selecionar a fonte de entrada anterior"

Clique no atalho atual e defina novo:
```

---

## ⚡ **Atalhos Recomendados:**

### **🔥 Opções Populares:**
- **`Ctrl + Shift + L`** ← **RECOMENDADO** (L = Layout)
- **`Ctrl + Alt + Space`** ← Alternativo
- **`Fn + Space`** ← Se tem tecla Fn no Sofle
- **`Option + Space`** ← Simples

### **❌ Evitar Conflitos:**
- **`⌘ + Space`** (Spotlight)
- **`⌃ + Space`** (Siri em alguns sistemas)
- **`Option + Tab`** (troca de apps)

---

## 🛠️ **Configuração Completa:**

### **Passo 1 - Adicionar Layouts:**
```
Configurações → Teclado → Fontes de Entrada → (+)

Adicione:
✅ Inglês (Estados Unidos)  
✅ Português (Brasil)
```

### **Passo 2 - Configurar Atalhos:**
```
Atalhos de Teclado → Fontes de Entrada:

📝 "Selecionar a próxima fonte de entrada": Ctrl+Shift+L
📝 "Selecionar a fonte de entrada anterior": Ctrl+Shift+K
```

### **Passo 3 - Testar:**
```
Pressione: Ctrl+Shift+L
Resultado: Layout deve trocar instantaneamente!
```

---

## 🎯 **Interface Visual:**

```
┌─────────────────────────────────────────────┐
│ 🍎 Configurações do Sistema                  │
├─────────────────────────────────────────────┤
│                                             │
│ 🔍 Buscar configurações...                  │
│                                             │
│ Teclado                                     │
│ ├─ Teclado                                  │
│ ├─ Texto                                    │
│ └─ Atalhos de Teclado                       │
│    └─ Fontes de Entrada ←── AQUI!          │
│                                             │
│ ┌─────────────────────────────────────────┐ │
│ │ ☑️ Selecionar próxima: ⌃⇧L              │ │
│ │ ☑️ Selecionar anterior: ⌃⇧K             │ │
│ └─────────────────────────────────────────┘ │
└─────────────────────────────────────────────┘
```

---

## ⚡ **Atalho Personalizado Inteligente:**

### **Minha Sugestão:**
```
🔧 PROGRAMAÇÃO: Ctrl + Shift + U (US)
💬 PORTUGUÊS:   Ctrl + Shift + B (Brazil)
```

**Como fazer:**
1. Configure **dois atalhos diferentes**
2. Um para **cada layout específico**
3. **Controle total** sobre qual vai ativar!

---

## 🎊 **Resultado Final:**

```
🔥 FLUXO IDEAL:
1. Abrindo VSCode → Ctrl+Shift+U → Layout US ativo
2. Abrindo Slack  → Ctrl+Shift+B → Layout BR ativo
3. ZERO FRICÇÃO! ⚡
```

---

## 🚀 **Integração com seu Sofle:**

Depois de configurar, você pode **mapear esses atalhos** no próprio teclado:

```c
// Macro no ZMK para trocar layout
Layout_US_Macro: 
  &kp LCTRL &kp LSHIFT &kp U

Layout_BR_Macro:
  &kp LCTRL &kp LSHIFT &kp B
```

**Quer que eu ajude a configurar isso também no keymap?** 🤔

