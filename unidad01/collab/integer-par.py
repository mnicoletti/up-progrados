sum_par = 0
cant_par = 0
cant_tres = 0
recorre = True

while recorre: # Se puede consultar si va a seguir ingresando numeros. Otra solucion es evaluar si el número es entero positivo y salir.
    entero = False
    while not entero:
        try:
            var_aux = int(input("Ingrese un número entero positivo: "))
            if var_aux <= 0:
                entero = False
            entero = True
        except ValueError:
            print("Error en ingreso.")
            entero = False
    
    if var_aux % 2 == 0:
        sum_par += var_aux
        cant_par += 1
    if var_aux % 3 == 0:
        cant_tres += 1
    control = input("Desea ingresar un nuevo valor? (s/n): ")
    while not ( control == 's' or control == 'n' ): # Esto se puede evaluar por una regex
        control = input("Desea ingresar un nuevo valor? (s/n): ")
    recorre = False if control == 'n' else True

print(f"Se encontraron {cant_par} números pares, cuyo promedio es: {sum_par / cant_par}")
print(f"Se encontraron {cant_tres} números divisibles por 3.")
