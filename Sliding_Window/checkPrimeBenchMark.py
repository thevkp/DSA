import time
import math

# def is_prime_square(n):
#     if n < 2:
#         return False
#     i = 2
#     while i * i <= n:
#         if n % i == 0:
#             return False
#         i += 1
#     return True
    
# cache i * i
def is_prime_square(n):
    if n < 2:
        return False
    i = 2
    i_squared = i * i
    while i_squared <= n:
        if n % i == 0:
            return False
        i += 1
        i_squared = i * i
    return True




def is_prime_sqrt(n):
    if n < 2:
        return False
    limit = int(math.sqrt(n))
    for i in range(2, limit + 1):
        if n % i == 0:
            return False
    return True

def count_primes(prime_func, N):
    count = 0
    for i in range(1, N + 1):
        if prime_func(i):
            count += 1
    return count

def run_battle(N):
    print(f"🧪 Prime checking up to {N}\n")

    # Battle 1: i * i <= n
    print("⚔️ Method 1: i * i <= n")
    start = time.time()
    count1 = count_primes(is_prime_square, N)
    time1 = time.time() - start
    print(f"   ✅ Primes found: {count1}")
    print(f"   ⏱️ Time: {time1:.4f} seconds\n")

    # Battle 2: i <= sqrt(n)
    print("⚔️ Method 2: i <= sqrt(n)")
    start = time.time()
    count2 = count_primes(is_prime_sqrt, N)
    time2 = time.time() - start
    print(f"   ✅ Primes found: {count2}")
    print(f"   ⏱️ Time: {time2:.4f} seconds\n")

    # Winner?
    print("🏁 Result:")
    if time1 < time2:
        print(f"   🥇 Winner: Method 1 by {time2 - time1:.4f} seconds!")
    else:
        print(f"   🥇 Winner: Method 2 by {time1 - time2:.4f} seconds!")

# 🔥 Start the battle
if __name__ == "__main__":
    N = 10**6  # You can raise this to 10**6 for serious combat
    run_battle(N)
