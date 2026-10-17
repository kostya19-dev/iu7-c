import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
from gui.lib_wrapper import (
    cyclic_shift_left,
    extract_perfect_squares,
    estimate_perfect_square_count,
)


class ArrayApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Array Operations")
        self.root.geometry("1200x300")
        self.root.style = ttk.Style()
        self.root.style.theme_use("clam")

        main_frame = ttk.Frame(root, padding="10")
        main_frame.pack(fill=tk.BOTH, expand=True)

        self.input_label = ttk.Label(
            main_frame, text="Enter array elements (comma-separated):"
        )
        self.input_label.pack(pady=5)

        self.input_entry = ttk.Entry(main_frame)
        self.input_entry.pack(fill=tk.X, pady=5)

        self.shift_label = ttk.Label(main_frame, text="Enter shift value (k):")
        self.shift_label.pack(pady=5)

        self.shift_entry = ttk.Entry(main_frame)
        self.shift_entry.pack(fill=tk.X, pady=5)

        button_frame = ttk.Frame(main_frame)
        button_frame.pack(pady=10)

        self.shift_button = ttk.Button(
            button_frame, text="Cyclic Shift", command=self.cyclic_shift
        )
        self.shift_button.grid(row=0, column=0, padx=5)

        self.extract_button = ttk.Button(
            button_frame,
            text="Extract Perfect Squares (Preallocated)",
            command=self.extract_squares_preallocated,
        )
        self.extract_button.grid(row=0, column=1, padx=5)

        self.dynamic_extract_button = ttk.Button(
            button_frame,
            text="Extract Perfect Squares (Dynamic Allocation)",
            command=self.extract_squares_dynamic,
        )
        self.dynamic_extract_button.grid(row=0, column=2, padx=5)

        self.result_label = ttk.Label(main_frame, text="", foreground="blue")
        self.result_label.pack(pady=10)

    def parse_input(self):
        try:
            return list(map(int, self.input_entry.get().split(",")))
        except ValueError:
            messagebox.showerror("Error", "Invalid input format.")
            return None

    def cyclic_shift(self):
        arr = self.parse_input()
        if arr is None:
            return

        try:
            k = int(self.shift_entry.get())
        except ValueError:
            messagebox.showerror("Error", "Invalid shift value.")
            return

        result = cyclic_shift_left(arr, k)
        self.result_label.config(text=f"Shifted Array: {result}")

    def extract_squares_preallocated(self):
        arr = self.parse_input()
        if arr is None:
            return

        result = extract_perfect_squares(arr)
        self.result_label.config(text=f"Perfect Squares: {result}")

    def extract_squares_dynamic(self):
        arr = self.parse_input()
        if arr is None:
            return

        required_size = estimate_perfect_square_count(arr)
        if required_size == 0:
            self.result_label.config(text="No perfect squares found.")
            return

        result = extract_perfect_squares(arr)
        self.result_label.config(text=f"Perfect Squares: {result}")


if __name__ == "__main__":
    root = tk.Tk()
    app = ArrayApp(root)
    root.mainloop()
