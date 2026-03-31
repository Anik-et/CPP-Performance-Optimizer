# C++ Execution Setup in Jupyter (Windows + MSYS2 + VS Code)

## Problem Statement

While building a pipeline to:

* Convert Python → C++ (using LLM)
* Compile using `g++`
* Benchmark execution

facing issues where:

* `g++` worked in CMD / VS Code terminal
* But failed inside Jupyter Notebook (`.ipynb`)

---

## ❌ Errors Encountered

### 1. g++ not recognized initially

```
'g++' is not recognized as an internal or external command
```

### 2. Inside Jupyter

```
FileNotFoundError
```

and

```
where g++ → INFO: Could not find files
```

---

## 🔍 Root Causes

1. **MSYS2 compiler not installed properly**
2. **PATH not configured in system environment**
3. **VS Code settings.json was invalid (multiple JSON objects)**
4. **Incorrect Python interpreter selected**
5. **Jupyter kernel not inheriting system PATH**
6. **Working directory mismatch in Jupyter**

---

## ✅ Step-by-Step Fix

### 1. Install Compiler using MSYS2

Open **MSYS2 MinGW64 terminal** and run:

```bash
pacman -S mingw-w64-x86_64-gcc
```

---

### 2. Add g++ to System PATH

Add this to Environment Variables:

```
C:\msys64\mingw64\bin
```

Verify in CMD:

```bash
g++ --version
```

---

### 3. Fix VS Code `settings.json`

Ensure only ONE valid JSON object:

```json
{
    "security.workspace.trust.untrustedFiles": "open",
    "window.zoomLevel": 2,
    "explorer.confirmDelete": false
}
```

---

### 4. Fix Python Interpreter Issue

* Removed invalid interpreter path
* Re-selected interpreter via:

```
Ctrl + Shift + P → Python: Select Interpreter
```

---

### 5. Fix Jupyter Working Directory

Check current directory:

```python
import os
os.getcwd()
```

If incorrect:

```python
os.chdir(r"YOUR_PROJECT_PATH")
```

---

### 6. Fix Jupyter Kernel PATH (CRITICAL)

Jupyter does not automatically inherit system PATH.

```python
import os
os.environ["PATH"] += r";C:\msys64\mingw64\bin"
```

Verify:

```python
import subprocess
subprocess.run("where g++", shell=True)
```

---

## 🧪 Final Working Pipeline

```python
import subprocess
import time

def compile_cpp(file_name):
    exe_name = file_name.replace(".cpp", ".exe")
    
    cmd = f'g++ "{file_name}" -O2 -o "{exe_name}"'
    
    result = subprocess.run(cmd, capture_output=True, text=True, shell=True)
    
    if result.returncode != 0:
        print("Compilation Error:")
        print(result.stderr)
        return None
    
    return exe_name

def run_exe(exe_name):
    start = time.time()
    
    result = subprocess.run(exe_name, capture_output=True, text=True, shell=True)
    
    end = time.time()
    
    print("Output:", result.stdout)
    print("Execution Time:", end - start)

exe = compile_cpp("test.cpp")
if exe:
    run_exe(exe)
```

---

## 🧠 Key Learnings

* VS Code Terminal ≠ Jupyter Kernel Environment
* System PATH must be explicitly available to subprocess
* Always verify working directory in notebooks
* Config errors (JSON) can silently break tooling
* Separate concerns:

  * Python env → logic
  * g++ → execution
  * Jupyter → orchestration

---

## 🚀 Next Steps

* Integrate LLM for Python → optimized C++ conversion
* Add benchmarking across multiple optimization flags (`-O2`, `-O3`)
* Compare Python vs C++ performance automatically

---
