import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../data/benchmark.csv")

# Runtime vs Cube Size

plt.figure(figsize=(8,5))

df.groupby(
    "CubeSize"
)["RuntimeMs"].mean().plot(
    marker="o"
)

plt.title("Runtime vs Cube Size")
plt.xlabel("Cube Size")
plt.ylabel("Runtime (ms)")
plt.grid(True)

plt.tight_layout()

plt.savefig("runtime_vs_size.png")

# Runtime vs Mask Ratio

plt.figure(figsize=(8,5))

df.groupby(
    "MaskRatio"
)["RuntimeMs"].mean().plot(
    marker="o"
)

plt.title("Runtime vs Mask Ratio")
plt.xlabel("Mask Ratio")
plt.ylabel("Runtime (ms)")
plt.grid(True)

plt.tight_layout()

plt.savefig("runtime_vs_mask.png")

# Recursive Calls

plt.figure(figsize=(8,5))

df.groupby(
    "MaskRatio"
)["RecursiveCalls"].mean().plot(
    marker="o"
)

plt.title("Recursive Calls vs Mask Ratio")
plt.xlabel("Mask Ratio")
plt.ylabel("Recursive Calls")
plt.grid(True)

plt.tight_layout()

plt.savefig("recursive_calls.png")

plt.show()
