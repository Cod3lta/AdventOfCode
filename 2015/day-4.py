import hashlib

input = "yzbqklnj"
number_max = 1000000                    # Pour éviter une boucle infinie
found = False                           # Pour savoir à la fin du programme si le résultat est trouvé
number_of_zeros = 6                     # Nombre de zéros à trouver au début du md5

progress_bar_width = 50                 # Taille de la progress bar

def print_progress(i):
    # Calculer le pourcentage de la recherche
    percentage = i / number_max * 100
    current_progress = int(progress_bar_width * percentage / 100)
    # Imprimer la progressbar
    for j in range(current_progress):
        print("#", end='')

    for j in range(progress_bar_width - current_progress):
        print("_", end='')
    print("", end="\r")

# Foreach incrémentant un integer
for i in range(number_max):
    # On met l'integer en string ici pour éviter de le faire plusieurs fois plus tard (+ performant)
    i_str = str(i)
    # On encode en md5 la string "input + i_str"
    md5_hex = hashlib.md5(str(input + i_str).encode('utf-8')).hexdigest()
    # On check si la string commence par "00000"
    if(md5_hex[:number_of_zeros] == "0" * number_of_zeros):
        # Si c'est le cas, on le print et on arrête la boucle
        print("Trouvé ! c'est : " + md5_hex + " avec le numéro " + i_str)
        print("Trouvé à " + str(i / number_max * 100) + "%")
        found = True
        break
    print_progress(i)

if not found:
    print("Aucun nombre n'a été trouvé dans l'intervalle 0-" + str(number_max))