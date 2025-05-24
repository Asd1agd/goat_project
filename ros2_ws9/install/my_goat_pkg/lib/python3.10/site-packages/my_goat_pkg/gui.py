import tkinter as tk
from tkinter import messagebox
from datetime import datetime

# Initial table_dict
table_dict = {
    "table1": [[["t1", [12, 30, 11], 1]], [["t1", [12, 30, 11], 1]]],
    "table2": [[["t2", [12, 30, 11], 2]], [["t2", [12, 30, 11], 2]]],
    "table3": [[["t3", [12, 30, 11], 3]], [["t3", [12, 30, 11], 3]]]
}

# Track canceled orders
order_canceled = []

# GLOBAL order ID
global_order_id = max(order[2] for table in table_dict.values() for order in table[0])

# Store GUI container references
table_gui_refs = {}  # {"table1": Frame, ...}
kitchen_gui_ref = None
wetter_gui_ref = None

# Global kitchen and wetter_robot lists
kitchen = [["t1", [12, 30, 11], 1], ["t2", [12, 30, 11], 2], ["t3", [12, 30, 11], 3], ["t1", [12, 3, 11], 5]]
wetter_robot = [["t1", [12, 30, 11], 1], ["t2", [12, 30, 11], 2], ["t3", [12, 30, 11], 3]]


def cancel_order(order, button):
    order_id = order[2]
    if order_id not in order_canceled:
        order_canceled.append(order_id)
        button.config(state="disabled")
        messagebox.showinfo("Order Canceled", f"Order ID {order_id} has been canceled.")
    else:
        messagebox.showwarning("Already Canceled", f"Order ID {order_id} was already canceled.")

    print("Canceled orders:", order_canceled)
    print("Updated table_dict:", table_dict)

    # Refresh GUI
    refresh_gui()


def add_order(table_name, container_frame):
    global global_order_id
    now = datetime.now()
    global_order_id += 1

    table_code = "t" + table_name[-1]
    order = [table_code, [now.hour, now.minute, now.second], global_order_id]

    # Add to both front-end and back-end lists
    table_dict[table_name][0].append(order)
    table_dict[table_name][1].append(order)

    print("Updated table_dict:", table_dict)

    # Refresh GUI
    refresh_gui()


def show_order_block(container, order, show_cancel=True):
    order_frame = tk.Frame(container, relief=tk.RIDGE, borderwidth=2, padx=5, pady=5)
    order_frame.pack(pady=10, fill="x")

    order_text = f"Table: {order[0]}\nTime: {order[1][0]:02d}:{order[1][1]:02d}:{order[1][2]:02d}\nOrder ID: {order[2]}"
    label = tk.Label(order_frame, text=order_text, justify="left")
    label.pack()

    if show_cancel:
        cancel_button = tk.Button(order_frame, text="Cancel Order")
        cancel_button.pack(pady=5)
        cancel_button.config(command=lambda o=order, b=cancel_button: cancel_order(o, b))


def refresh_gui():
    """Rebuilds the GUI content based on current table_dict."""
    for table_name, (visible_orders, _) in table_dict.items():
        container = table_gui_refs.get(table_name)
        if container:
            for widget in container.winfo_children():
                widget.destroy()
            for order in visible_orders:
                show_order_block(container, order)

    # Refresh kitchen
    if kitchen_gui_ref:
        for widget in kitchen_gui_ref.winfo_children():
            widget.destroy()
        for order in kitchen:
            show_order_block(kitchen_gui_ref, order, show_cancel=False)

    # Refresh wetter
    if wetter_gui_ref:
        for widget in wetter_gui_ref.winfo_children():
            widget.destroy()
        for order in wetter_robot:
            show_order_block(wetter_gui_ref, order, show_cancel=False)


def create_gui():
    global kitchen_gui_ref, wetter_gui_ref

    root = tk.Tk()
    root.title("Order Manager")
    root.geometry("1600x600")

    # Create table columns
    for col_index, (table_name, (visible_orders, _)) in enumerate(table_dict.items()):
        table_frame = tk.LabelFrame(root, text=table_name.upper(), padx=10, pady=10)
        table_frame.grid(row=0, column=col_index, padx=20, pady=20, sticky="n")

        orders_container = tk.Frame(table_frame)
        orders_container.pack()

        table_gui_refs[table_name] = orders_container  # Save reference

        for order in visible_orders:
            show_order_block(orders_container, order)

        add_button = tk.Button(
            table_frame,
            text="Add Order",
            command=lambda tn=table_name, f=orders_container: add_order(tn, f)
        )
        add_button.pack(pady=10)

    # Kitchen block
    kitchen_frame = tk.LabelFrame(root, text="KITCHEN", padx=10, pady=10)
    kitchen_frame.grid(row=0, column=len(table_dict), padx=20, pady=20, sticky="n")
    kitchen_gui_ref = tk.Frame(kitchen_frame)
    kitchen_gui_ref.pack()

    # Wetter block
    wetter_frame = tk.LabelFrame(root, text="WETTER", padx=10, pady=10)
    wetter_frame.grid(row=0, column=len(table_dict) + 1, padx=20, pady=20, sticky="n")
    wetter_gui_ref = tk.Frame(wetter_frame)
    wetter_gui_ref.pack()

    refresh_gui()

    root.mainloop()

    print("Canceled orders:", order_canceled)
    print("Final table_dict:", table_dict)


if __name__ == "__main__":
    create_gui()
