# Porównanie technik kodowania C++ oraz Blueprint w&nbsp;środowisku Unreal Engine

Sceny zostały podzielone na osobne foldery w zależności od eksperymentu i technologi implementacji.

## Wersja Silnika i Narzędzia
Wszystkie projekty w tym repozytorium zostały stworzone i są kompatybilne z poniższą konfiguracją:
* **Silnik:** Unreal Engine 5.6.1 (`5.6.1-44394996+++UE5+Release-5.6`)
* **Środowisko programistyczne:** Visual Studio 2022

---

## Struktura Projektu

Repozytorium składa się z 6 niezależnych folderów, z których każdy zawiera osobny projekt Unreal Engine (`.uproject`):

* **`scena1_C++`** - symulacja wielu agentów zaimplementowana z wykorzystaniem kodu C++.
* **`scena1_blueprint`** - symulacja wielu agentów zaimplementowana w oparciu o system Blueprints.
* **`scena2`** - Scena z środowiskiem i kamerą kinową.
* **`scena3`** – Scena z benchmarkiem.
* **`scena4_C++`** – Scena testowa tworzenia obiektów zaimplementowana z wykorzystaniem kodu C++.
* **`scena4_blueprint`** – Scena testowa tworzenia obiektów zaimplementowana w oparciu o system Blueprints.

---

## Sterowanie (Scena 2)
Podczas uruchomienia **sceny 2** dostępne są dedykowane skróty klawiszowe umożliwiające testowanie i&nbsp;porównywanie działania skryptów:

* **`B`** – Zmienia aktywny kontroler z&nbsp;C++ na Blueprint i&nbsp;odwrotnie.
* **`N`** – Włącza lub wyłącza działanie kontrolerów.

---

### Instrukcja uruchomienia:

1. **Pobranie i wypakowanie repozytorium**.
2. **Wejście do wybranego folderu** (np. `scena1_C++` lub `scena2`).
3. dwukrotne kliknięcie pliku z rozszerzeniem **`.uproject`** (np. `scena3.uproject`).

#### Ważne: Rebuild Modułów (Projekty C++)
Podczas pierwszego uruchamiania projektów zawierających kod C++, Unreal Engine wyświetli komunikat informujący o braku skompilowanych plików binarnych:

> *"The following modules are missing or built with a different engine version... Would you like to rebuild them now?"*

1. W oknie komunikatu należy kliknąć przycisk **Yes** (Tak).
2. Po pomyślnym zakończeniu kompilacji edytor Unreal Engine uruchomi się automatycznie.
