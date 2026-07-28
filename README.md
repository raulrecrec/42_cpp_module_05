*This project has been created as part of the 42 curriculum by rexposit.*

# CPP Module 05

`CPP Module 05` is part of the C++ modules of the 42 curriculum. The project introduces exception handling, abstract classes and runtime polymorphism by building a progressively more complex bureaucracy system.

Throughout the module, bureaucrats gain the ability to sign and execute forms, while concrete forms implement different actions. The final exercise adds an `Intern` capable of dynamically creating forms through a simple factory method.

---

# Table of Contents

- [Description](#description)
- [Project Rules](#project-rules)
- [Exercises Overview](#exercises-overview)
- [Class Hierarchy](#class-hierarchy)
- [Implementation](#implementation)
- [Compilation](#compilation)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [What I Learned](#what-i-learned)
- [Author](#author)

---

# Description

CPP Module 05 is divided into four independent exercises, each extending the previous one.

### ex00 — Bureaucrat

Introduces the `Bureaucrat` class.

A bureaucrat has:

- an immutable name;
- a grade between **1** and **150**;
- grade increment and decrement operations;
- custom exceptions when grades become invalid.

This exercise focuses on exception handling and object validation.

---

### ex01 — Form

Introduces the `Form` class.

A form stores:

- its name;
- its signed state;
- the minimum grade required to sign it;
- the minimum grade required to execute it.

A bureaucrat can attempt to sign a form if their grade is high enough.

This exercise models the interaction between multiple classes.

---

### ex02 — Concrete Forms

`Form` becomes the abstract class `AForm`.

Three concrete forms are implemented:

- `ShrubberyCreationForm`
- `RobotomyRequestForm`
- `PresidentialPardonForm`

Each form performs a different action while sharing the same validation logic through the abstract base class.

Execution permissions are checked before the concrete action is performed.

---

### ex03 — Intern

The final exercise introduces the `Intern` class.

Instead of creating forms directly, the client requests a form by name.

The intern dynamically creates the appropriate object and returns it through an `AForm*`.

Unknown form names are handled safely by returning `NULL`.

---

# Project Rules

The project follows the requirements of CPP Module 05.

- C++98 standard
- Orthodox Canonical Form
- Compilation with:

```bash
-Wall -Wextra -Werror -std=c++98
```

- Nested exception classes
- Proper dynamic memory management
- Runtime polymorphism
- Virtual destructors where required

---

# Exercises Overview

| Exercise | Main Concept | Executable |
|----------|--------------|------------|
| ex00 | Bureaucrats and exceptions | `bureaucrat` |
| ex01 | Forms and signing | `form` |
| ex02 | Abstract classes and polymorphism | `forms` |
| ex03 | Factory Method with Intern | `interns` |

---

# Class Hierarchy

```text
                    Bureaucrat
                         │
                         │ signs / executes
                         ▼
                      AForm
                         ▲
         ┌───────────────┼───────────────┐
         │               │               │
         ▼               ▼               ▼
 Shrubbery        Robotomy Request   Presidential
CreationForm            Form         PardonForm

                         ▲
                         │
                      Intern
```

The `Intern` only creates forms.

Execution logic remains inside `AForm` and the concrete derived classes.

---

# Implementation

## Bureaucrat

Responsible for storing:

- name
- grade

Provides:

- grade validation
- increment/decrement
- custom exceptions
- stream operator

---

## AForm

Stores all common form data:

- name
- signed state
- signing grade
- execution grade

The base class validates execution before calling the derived implementation through:

```cpp
executeAction()
```

This avoids duplicating permission checks.

---

## Concrete Forms

### ShrubberyCreationForm

Creates:

```text
<target>_shrubbery
```

containing ASCII trees.

---

### RobotomyRequestForm

Prints drilling noises and randomly succeeds or fails.

---

### PresidentialPardonForm

Prints a message indicating that the target has been pardoned by Zaphod Beeblebrox.

---

## Intern

Creates forms dynamically through:

```cpp
AForm *makeForm(const std::string &form_name, const std::string &target) const;
```

Supported names:

- shrubbery creation
- robotomy request
- presidential pardon

Unknown names return `NULL`.

---

# Compilation

Each exercise is independent.

Compile any exercise by entering its directory.

Example:

```bash
cd ex02
make
./forms
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

---

# Testing

The test programs verify:

- valid and invalid bureaucrat grades;
- successful and failed form signing;
- execution permissions;
- shrubbery file generation;
- robotomy randomness;
- presidential pardons;
- unknown form requests;
- execution of unsigned forms;
- insufficient execution grades.

Memory usage can be checked with:

```bash
valgrind --leak-check=full ./interns
```

---

# Project Structure

```text
42_cpp_module_05/
│
├── ex00/
│   ├── Bureaucrat.*
│   ├── main.cpp
│   └── Makefile
│
├── ex01/
│   ├── Bureaucrat.*
│   ├── Form.*
│   ├── main.cpp
│   └── Makefile
│
├── ex02/
│   ├── Bureaucrat.*
│   ├── AForm.*
│   ├── ShrubberyCreationForm.*
│   ├── RobotomyRequestForm.*
│   ├── PresidentialPardonForm.*
│   ├── main.cpp
│   └── Makefile
│
├── ex03/
│   ├── Bureaucrat.*
│   ├── AForm.*
│   ├── ShrubberyCreationForm.*
│   ├── RobotomyRequestForm.*
│   ├── PresidentialPardonForm.*
│   ├── Intern.*
│   ├── main.cpp
│   └── Makefile
│
└── README.md
```

---

# What I Learned

Through this module I strengthened my understanding of:

- exception handling;
- nested exception classes;
- inheritance;
- abstract classes;
- runtime polymorphism;
- virtual destructors;
- dynamic memory management;
- object-oriented design;
- reusable class hierarchies;
- the Factory Method pattern.

CPP Module 05 progressively transforms a simple class into a complete object-oriented system composed of reusable and polymorphic components.

---

# Author

**Raúl Expósito Campos**

42 Madrid Student

GitHub: https://github.com/raulrecrec