import numpy as np

N_BITS = 10
SIZE = 20
measures = np.random.randint(0, pow(2,N_BITS)-1, SIZE) # Conversor A/D de 10 bit


with open('medidas.txt', 'a') as file:
    for i in measures:
        file.write(bin(i))
        file.write('\n')
print(f"Escritura de {SIZE} valores de 10 bits.", end="")
print(f"(valores de 0 a {pow(2,N_BITS)-1})")