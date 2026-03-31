⚡ AI-Driven Python-to-C++ Performance Optimizer

A powerful benchmarking and translation tool that uses advanced Large Language Models (LLMs) to automatically convert slow Python scripts into hyper-optimized C++20 code. The system compiles the generated code, runs it, and calculates the exact execution speedup multiplier.

Whether you are testing the coding capabilities of the latest AI models or trying to optimize a bottleneck in your Python project, this tool provides an automated, frictionless pipeline to get it done.

✨ Features

Multi-Model Support (The Industrial Router): Instantly route prompts to Local models (Ollama), Free Cloud APIs (Groq, OpenRouter, Google), and Paid APIs (OpenAI, Anthropic, xAI).

Interactive Web UI: A clean, symmetrical Gradio interface to view, edit, and manually test Python vs. C++ code side-by-side.

Bulletproof Compiler Catching: Safely extracts C++ code from LLM responses, wraps it for compilation, and catches silent Linker/MinGW errors on Windows.

🚀 Setup & Installation

1. Prerequisites

Python 3.8+ installed on your system.

C++ Compiler: You must have g++ installed. (For Windows users, install MinGW/MSYS2 and ensure C:\msys64\mingw64\bin is in your system PATH).

Ollama (Optional but recommended): Required if you want to run local models. Download at ollama.com.

2. Clone the Repository
```
git clone [https://github.com/YourUsername/cpp-performance-optimizer.git](https://github.com/YourUsername/cpp-performance-optimizer.git)
cd cpp-performance-optimizer
```

3. Install Python Dependencies

It is highly recommended to use a virtual environment:

python -m venv venv
# Windows:
```.\venv\Scripts\activate```
# Mac/Linux:
```source venv/bin/activate```

# Install Relevant packages
```
pip install -r requirements.txt
```


4. Setup Local AI Models (Ollama)

If you want to test local offline models, pull them via Ollama:
```
ollama pull qwen2.5-coder:7b
ollama pull llama3.1
```

5. Configure API Keys

Create a file named .env in the root directory of the project and add your API keys. All keys are optional—the app will gracefully skip models you don't have keys for!

# .env file
```
OPENAI_API_KEY=sk-your-key-here

ANTHROPIC_API_KEY=sk-ant-your-key-here

GEMINI_API_KEY=AIza-your-key-here

GROK_API_KEY=xai-your-key-here

GROQ_API_KEY=gsk_your-key-here

OPENROUTER_API_KEY=sk-or-your-key-here
```

💻 How to Use

The Interactive Web UI

To launch the Gradio web interface, simply open and run the main Jupyter Notebook file. You can do this via VS Code by clicking "Run All", or via the command line:
```
jupyter notebook main.ipynb
```

This will open a local web server (usually at http://127.0.0.1:7860). You can type Python code on the left, select an AI model, generate C++ code on the right, and compile/run it to compare execution times.

🤖 Supported Models Configured

Local: Qwen 2.5 Coder 7B, Llama 3.1 8B

Free Cloud: Gemini 2.5 Flash, Llama 3.3 70B (Groq), Llama 3.1 8B (Groq), Gemma 2 9B (OpenRouter)

Paid Cloud: GPT-4o, Claude 3.5 Sonnet, Grok 2

(You can easily add or remove models by editing the AVAILABLE_MODELS dictionary inside main.ipynb!)

⚠️ Known Limitations

The script is currently optimized for single-file main.cpp execution.

Complex Python libraries (like Pandas or NumPy) cannot be directly translated into standard C++ without external C++ libraries. Keep the baseline Python code focused on pure computational logic, math, and standard data structures!
