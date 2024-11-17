import random
import string

#----------------------------------FUNCION PARA CREAR CADENAS----------------------------------

def generar_cadenas(largo_min, largo_max, mismo_largo, solo_un_caracter, caracteres_permitidos):
    if mismo_largo:
        largo1 = largo2 = random.randint(largo_min, largo_max)
    else:
        largo1 = random.randint(largo_min, largo_max)
        largo2 = random.randint(largo_min, largo_max)
    
    if solo_un_caracter:
        caracter1 = random.choice(caracteres_permitidos)
        caracter2 = random.choice(caracteres_permitidos)
        cadena1 = caracter1 * largo1
        cadena2 = caracter2 * largo2
    else:
        cadena1 = ''.join(random.choice(caracteres_permitidos) for _ in range(largo1))
        cadena2 = ''.join(random.choice(caracteres_permitidos) for _ in range(largo2))
    
    return cadena1, cadena2

#-------------------FUNCION PARA CREAR LAS LINEAS COSTO DE INSERT Y DELETE---------------------

def generar_linea(valor_min, valor_max, solo_un_numero):
    if solo_un_numero:
        numero = random.randint(valor_min, valor_max)
        linea = [numero for _ in range(26)]
    else:
        linea = [random.randint(valor_min, valor_max) for _ in range(26)]
    return linea

#------------------FUNCION PARA CREAR LAS MATRICES COSTO REPLACE Y TRANSPOSE-------------------

def generar_matriz(valor_min, valor_max, solo_un_numero):
    if solo_un_numero:
        numero = random.randint(valor_min, valor_max)
        matriz = [[numero for _ in range(26)] for _ in range(26)]
    else:
        matriz = [[random.randint(valor_min, valor_max) for _ in range(26)] for _ in range(26)]
    for i in range(26):
        matriz[i][i] = 0
    return matriz

#---------------------------FUNCION PARA CREAR LAS MATRICES COSTO-------------------------------

def generar_matrices(valor_min, valor_max, solo_un_numero):
    matrices = []
    for _ in range(2):
        matrices.append(generar_linea(valor_min, valor_max, solo_un_numero))
    for _ in range(2):
        matrices.append(generar_matriz(valor_min, valor_max, solo_un_numero))
    return matrices

#---------------------------FUNCION PARA ESCRIBIR LAS MATRICES COSTO---------------------------

def escribir_matriz_en_archivo(matriz, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        if isinstance(matriz[0], int):
            archivo.write(" ".join(map(str, matriz)) + '\n')
        else:
            for fila in matriz:
                archivo.write(" ".join(map(str, fila)) + '\n')

#--------------------------------------PARAMETROS CADENAS--------------------------------------

print("\n---------------------PARAMETROS CADENAS---------------------")
largo_min = int(input("Largo mínimo de las cadenas: "))
largo_max = int(input("Largo máximo de las cadenas: "))
mismo_largo = input("¿Deben tener el mismo largo? (s/n): ").strip().lower() == 's'
solo_un_caracter = input("¿Deben tener un solo caracter repetido? (s/n): ").strip().lower() == 's'
usar_todo_abecedario = input("¿Usar todo el abecedario (ingles y minusculas)? (s/n): ").strip().lower() == 's'
if usar_todo_abecedario:
    caracteres_permitidos = string.ascii_lowercase
else:
    caracteres_permitidos = input("Ingrese los caracteres permitidos (sin espacios): ").strip()

#------------------------------------ESCRITURA AMBAS CADENAS------------------------------------

cadena1, cadena2 = generar_cadenas(largo_min, largo_max, mismo_largo, solo_un_caracter, caracteres_permitidos)
with open("cadenas.txt", 'w') as archivo:
    archivo.write(cadena1 + '\n')
    archivo.write(cadena2 + '\n')

#------------------------------------PARAMETROS MATRICES COSTO----------------------------------

print("-----------------PARAMETROS MATRICES COSTO------------------")
valor_min = int(input("Valor mínimo para los costos en las matrices: "))
valor_max = int(input("Valor máximo para los números en las matrices: "))
solo_un_numero = input("¿Deben tener un solo número repetido? (s/n): ").strip().lower() == 's'
print("------------------------------------------------------------\n")

#------------------------------------ESCRITURA MATRICES COSTO-----------------------------------

matrices = generar_matrices(valor_min, valor_max, solo_un_numero)
nombres_archivos = ["cost_insert.txt", "cost_delete.txt", "cost_replace.txt", "cost_transpose.txt"]

for matriz, nombre_archivo in zip(matrices, nombres_archivos):
    escribir_matriz_en_archivo(matriz, nombre_archivo)