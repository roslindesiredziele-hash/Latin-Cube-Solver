import pandas as pd
import matplotlib.pyplot as plt

# Load benchmark data
df = pd.read_csv("data/benchmark.csv")

plt.style.use("default")

# --------------------------------------------------
# Graph 1: Runtime vs Cube Size
# --------------------------------------------------

plt.figure(figsize=(10, 6))

for ratio in sorted(df["MaskRatio"].unique()):
    subset = df[df["MaskRatio"] == ratio]

    plt.plot(
        subset["CubeSize"],
        subset["RuntimeMs"],
        marker="o",
        linewidth=2,
        label=f"Mask Ratio {ratio:.1f}"
    )

plt.title("Runtime vs Cube Size")
plt.xlabel("Cube Size (n)")
plt.ylabel("Runtime (ms)")
plt.grid(True, alpha=0.3)
plt.legend()

plt.tight_layout()
plt.savefig("runtime_vs_size.png", dpi=300)

# --------------------------------------------------
# Graph 2: Runtime vs Mask Ratio
# --------------------------------------------------

plt.figure(figsize=(10, 6))

for size in sorted(df["CubeSize"].unique()):
    subset = df[df["CubeSize"] == size]

    plt.plot(
        subset["MaskRatio"],
        subset["RuntimeMs"],
        marker="o",
        linewidth=2,
        label=f"Size {size}"
    )

plt.title("Runtime vs Mask Ratio")
plt.xlabel("Mask Ratio")
plt.ylabel("Runtime (ms)")
plt.grid(True, alpha=0.3)
plt.legend()

plt.tight_layout()
plt.savefig("runtime_vs_mask_ratio.png", dpi=300)

# --------------------------------------------------
# Graph 3: Recursive Calls vs Cube Size
# --------------------------------------------------

plt.figure(figsize=(10, 6))

for ratio in sorted(df["MaskRatio"].unique()):
    subset = df[df["MaskRatio"] == ratio]

    plt.plot(
        subset["CubeSize"],
        subset["RecursiveCalls"],
        marker="o",
        linewidth=2,
        label=f"Mask Ratio {ratio:.1f}"
    )

plt.title("Recursive Calls vs Cube Size")
plt.xlabel("Cube Size (n)")
plt.ylabel("Recursive Calls")
plt.grid(True, alpha=0.3)
plt.legend()

plt.tight_layout()
plt.savefig("recursive_calls_vs_size.png", dpi=300)

plt.show()