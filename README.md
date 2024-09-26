README
CODIGO CREADO POR LOS INTEGRANTES:
Nicolas Antonio Rojas Bustos, 21.295.708-9, nicolas.rojas11@alumnos.ucn.cl, paralelo C2
Ramses Balthazar Quintanilla Paez, 21.620.464-6, ramses.quintanilla@alumnos.ucn.cl, paralelo C2

IMPORTANTE:

comando de compilacion: g++ -o main MaterialBibliografico.cpp Revista.cpp Libro.cpp Usuario.cpp system.cpp main.cpp

comando de ejecucion: ./main

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

-Objetos creados (materiales):

Libro: {
  titulo: "Networks",
  isbn: "341",
  autor: "Diana Reyes",
  prestado: "no prestado",
  fecha de publicación: "30/10/97",
  resumen: "Excelente recurso para aprender nuevas ideas."
},
Libro: {
  titulo: "Lost Worlds",
  isbn: "7121",
  autor: "Luis Anderson",
  prestado: "no prestado",
  fecha de publicación: "26/07/17",
  resumen: "Una guía fascinante para el futuro."
},
Revista: {
  titulo: "Como mejorar en lol",
  isbn: "99",
  autor: "manute",
  prestado: "no prestado",
  mes de publicación: "101",
  edicion: "febrero"
},
Libro: {
  titulo: "Astrobiology",
  isbn: "1133",
  autor: "Emily Parker",
  prestado: "no prestado",
  fecha de publicación: "21/06/98",
  resumen: "Reflexiones profundas sobre la evolución humana."
},
Revista: {
  titulo: "Descubrimientos Genéticos",
  isbn: "23",
  autor: "Dr. Antonio Ruiz",
  prestado: "no prestado",
  mes de publicación: "3455",
  edicion: "Enero"
},
Libro: {
  titulo: "AI Revolution",
  isbn: "187",
  autor: "Jon Snow",
  prestado: "no prestado",
  fecha de publicación: "24/02/90",
  resumen: "Una guía fascinante para el futuro."
},
Libro: {
  titulo: "Nanotechnology",
  isbn: "178",
  autor: "Alex Kim",
  prestado: "no prestado",
  fecha de publicación: "02/02/20",
  resumen: "Una guía fascinante para el futuro."
},
Revista: {
  titulo: "Fauna en Extinción",
  isbn: "725",
  autor: "Biól. Andrés González",
  prestado: "no prestado",
  mes de publicación: "4876",
  edicion: "Mayo"
},
Libro: {
  titulo: "Cosmic Frontiers",
  isbn: "108",
  autor: "Robert Harrison",
  prestado: "no prestado",
  fecha de publicación: "09/02/91",
  resumen: "Reflexiones profundas sobre la evolución humana."
},
Revista: {
  titulo: "Science",
  isbn: "1734",
  autor: "Okami",
  prestado: "no prestado",
  mes de publicación: "120",
  edicion: "Diciembre"
},
Libro: {
  titulo: "Futuristic Medicine",
  isbn: "944",
  autor: "Lucía Blanco",
  prestado: "no prestado",
  fecha de publicación: "30/06/03",
  resumen: "Perspectivas asombrosas sobre la tecnología."
},
Libro: {
  titulo: "Alien Civilizations",
  isbn: "646",
  autor: "Sophia Morgan",
  prestado: "no prestado",
  fecha de publicación: "21/07/07",
  resumen: "Reflexiones profundas sobre la evolución humana."
},
Libro: {
  titulo: "Deep Learning",
  isbn: "893",
  autor: "Nathan Hughes",
  prestado: "no prestado",
  fecha de publicación: "19/06/17",
  resumen: "Perspectivas asombrosas sobre la tecnología."
},
Revista: {
  titulo: "Diseño Urbano Sustentable",
  isbn: "6654",
  autor: "Arq. Laura Sánchez",
  prestado: "no prestado",
  mes de publicación: "2678",
  edicion: "Abril"
},
Libro: {
  titulo: "Virtual Realities",
  isbn: "568",
  autor: "Sasha Ivanov",
  prestado: "no prestado",
  fecha de publicación: "23/03/93",
  resumen: "Un libro intrigante sobre lo desconocido."
},
Revista: {
  titulo: "Inteligencia Artificial en la Medicina",
  isbn: "002",
  autor: "Ing. María López",
  prestado: "no prestado",
  mes de publicación: "333",
  edicion: "Febrero"
},
Libro: {
  titulo: "Machine Learning",
  isbn: "835",
  autor: "Gabriel Rose",
  prestado: "no prestado",
  fecha de publicación: "04/09/04",
  resumen: "Perspectivas asombrosas sobre la tecnología."
},
Libro: {
  titulo: "The Quantum Computer",
  isbn: "397",
  autor: "James Kepler",
  prestado: "no prestado",
  fecha de publicación: "27/03/13",
  resumen: "Perspectivas asombrosas sobre la tecnología."
},
Libro: {
  titulo: "Biohacking 101",
  isbn: "170",
  autor: "Daniel West",
  prestado: "no prestado",
  fecha de publicación: "22/03/09",
  resumen: "Una guía fascinante para el futuro."
},
Revista: {
  titulo: "Civilizaciones Antiguas",
  isbn: "2133",
  autor: "Prof. Jaime Pérez",
  prestado: "no prestado",
  mes de publicación: "7345",
  edicion: "Marzo"
}

-Objetos creados (Usuarios):

{
  Nombre: "Manute",
  ID: "23"
},
{
  Nombre: "Sakura",
  ID: "34"
},
{
  Nombre: "Lucía",
  ID: "45"
},
{
  Nombre: "Carlos",
  ID: "56"
},
{
  Nombre: "Felipe",
  ID: "67"
},
{
  Nombre: "Kathalina",
  ID: "21"
},
{
  Nombre: "María",
  ID: "78"
},
{
  Nombre: "Javier",
  ID: "89"
},
{
  Nombre: "Ana",
  ID: "90"
},
{
  Nombre: "Nicolas",
  ID: "25"
},
{
  Nombre: "Sofía",
  ID: "101"
},
{
  Nombre: "David",
  ID: "112"
},
{
  Nombre: "Laura",
  ID: "123"
},
{
  Nombre: "Andrés",
  ID: "134"
},
{
  Nombre: "Elena",
  ID: "145"
},
{
  Nombre: "Roberto",
  ID: "156"
},
{
  Nombre: "Ramses",
  ID: "20"
},
{
  Nombre: "Okami",
  ID: "18"
}
