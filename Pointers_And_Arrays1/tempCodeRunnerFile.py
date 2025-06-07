from fpdf import FPDF

# Create a PDF document
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()
pdf.set_font("Arial", size=12)

# Title
pdf.set_font("Arial", style="B", size=16)
pdf.cell(200, 10, "Variations of the Find Pairs with a Given Sum Problem", ln=True, align="C")
pdf.ln(10)

# Problems content
problems_with_examples = [
    "Basic Variations:",
    "1. Simple Pair Sum (Unsorted Array): Find all pairs in an unsorted array that sum to a given target.\n   Example: Array = [1, 4, 7, 5], Target = 9; Result: [(4, 5)]",
    "2. Pair Sum with Unique Pairs: Find pairs but avoid duplicate pairs.\n   Example: Array = [1, 4, 4, 5], Target = 9; Result: [(4, 5)]",
    "3. Pair Sum in a Sorted Array: Given a sorted array, find all pairs using a two-pointer approach.\n   Example: Array = [1, 3, 4, 5], Target = 6; Result: [(1, 5), (3, 3)]",
    "",
    "Intermediate Variations:",
    "4. Count of Pairs with Target Sum: Return the count of pairs instead of the actual pairs.\n   Example: Array = [1, 4, 7, 5], Target = 9; Result: 1",
    "5. Pairs with Distinct Elements Only: Ignore pairs where both elements are the same.\n   Example: Array = [4, 4, 7], Target = 8; Result: []",
    "6. Pairs from Two Separate Arrays: Find pairs where one element is from Array A and the other from Array B.\n   Example: Array A = [1, 2], Array B = [3, 4], Target = 5; Result: [(1, 4), (2, 3)]",
    "",
    "Advanced Variations:",
    "7. Triplets with Target Sum: Extend the problem to find triplets that sum to the target.\n   Example: Array = [1, 2, 3, 4], Target = 7; Result: [(1, 2, 4)]",
    "8. Quadruples with Target Sum: Find quadruples using hash-based or two-pointer methods.\n   Example: Array = [1, 2, 3, 4, 5], Target = 10; Result: [(1, 2, 3, 4)]",
    "9. Pairs with Closest Sum to Target: Find the pair whose sum is closest to the target.\n   Example: Array = [1, 3, 5, 8], Target = 7; Result: [(3, 5)]",
    "10. Pairs with Difference Equal to Target: Find pairs where the difference equals a target.\n    Example: Array = [1, 5, 7], Target = 4; Result: [(1, 5)]",
    "11. Pairs with Product Equal to Target: Find pairs whose product equals a given target.\n    Example: Array = [2, 4, 8], Target = 8; Result: [(2, 4)]",
    "",
    "Advanced Real-World Variations:",
    "12. Pairs from Arrays with Constraints: Satisfy additional constraints, such as indices differing by a minimum value.\n    Example: Array = [1, 5, 6, 7], Constraint: Indices differ by >= 2, Target = 6; Result: [(1, 5)]",
    "13. Pairs with Maximum/Minimum Sum Below Target: Find the pair with the maximum/minimum sum below the target.\n    Example: Array = [2, 4, 6], Target = 7; Result: [(2, 4)]",
    "14. Weighted Pair Sum Problem: Consider associated weights for each number in the array.\n    Example: Array = [(1, 2), (3, 4)], Target = 6; Result: [(1, 3)]",
    "15. Pairs with Sum Modulo Target: Find pairs where the sum modulo a value equals a specific remainder.\n    Example: Array = [2, 4, 6], Mod = 5, Remainder = 1; Result: [(4, 6)]",
    "16. Find All Pairs Using a Sliding Window: Process pairs from a continuous stream of numbers with limited memory.\n    Example: Stream = [1, 2, 3, 4], Target = 5; Result: [(1, 4), (2, 3)]",
    "",
    "Challenge Variations:",
    "17. Find Pairs in Rotated Sorted Array: Solve efficiently in a rotated sorted array.\n    Example: Array = [4, 5, 1, 2], Target = 6; Result: [(4, 2)]",
    "18. Count All Pairs (Faster than O(n^2)): Count all pairs using optimized algorithms.\n    Example: Array = [1, 1, 1, 2], Target = 2; Result: 3",
    "19. K Pairs with Largest Sums: Return the k pairs with the largest sums from two arrays.\n    Example: Array A = [1, 2], Array B = [3, 4], k = 2; Result: [(2, 4), (2, 3)]",
    "20. Pairs with Constraints on Indices or Value Ranges: Add constraints like 'both elements must be even.'\n    Example: Array = [2, 4, 6], Target = 10, Constraint: Both even; Result: [(4, 6)]",
]

# Add the problems with examples to the PDF
pdf.set_font("Arial", size=12)
for line in problems_with_examples:
    pdf.multi_cell(0, 10, line)

# Save to a file
output_path = "C:/Users/vk132/DownloadsFind_Pairs_Problem_Variations_with_Examples.pdf"

pdf.output(output_path)

output_path
