README
CODIGO CREADO POR LOS INTEGRANTES:
Nicolas Antonio Rojas Bustos, 21.295.708-9, nicolas.rojas11@alumnos.ucn.cl, paralelo C2
Ramses Balthazar Quintanilla Paez, 21.620.464-6, ramses.quintanilla@alumnos.ucn.cl, paralelo C2

IMPORTANTE:
EL CODIGO ESTA CREADO PARA QUE PUEDA FUNCIONAR TANTO EN UN CODESPACE DE GITHUB EN EL NAVEGADOR WEB LO CUAL ES UN ENTORNO (LINUX) POR LO QUE A LA HORA DE EJECUTAR DEBE DE OCUPAR LA OPCION C/C++: g++ build active file (Linux).

EN CASO DE EJECUTAR EN VSCODE O UN EDITOR EN ENTORNO DE WINDOWS SOLO SELECCIONE LA OPCION DE C/C++: g++ build active file (MSYS2 - Windows).
DE IGUAL MANERA SE CREO UN EJECUTABLE EL CUAL DEBERIA ESTAR LISTO PARA FUNCIONAR LLAMADO main.exe

TODO ESTO CON EL FIN DE EVITAR ALGUN ERROR. GRACIAS.

RECOMENDACIONES INICIALES:
El menu cuenta con 7 opciones, de las cuales lo mas recomendable para comenzar con una ejecucion rapida y cargar los datos, es recomendable
comenzar ejecutando la opcion 6. Gestion de Datos.
Seguido de esto se debe ejecutar la opcion 1. Carga de Materiales, para tener todo el material disponible el cual ocupa el 50% del espacio todal de nuestra lista para
el almacenamiento de la biblioteca el cual es [100].
Luego ejecutar opcion 2. Carga de Usuarios en el mismo menu de Gestion de datos, junto con esto se rellena la mitad de la lista de usuarios disponibles para utilizar.

Todo el material es constantemente guardado en los archivos usuarios.txt y materiales.txt
al terminar estos paso iniciales se crean los objetos usuarios con los atributos (nombre, identificador)
y dependiendo de si lo que se inicializa en materiales se inicializaran con los atributos (nombre, isbn, autor, estado de prestamo)
si es un libro a este se le agregaran los atributos (fecha de publicacion, resumen) 
y en el caso que sea una revista se le agregaran los atributos (numero de edicion, mes de publicacion).
