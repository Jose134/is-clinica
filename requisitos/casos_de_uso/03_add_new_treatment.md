# Añadir nuevo tratamiento a paciente

**ID:** 03 

**Descripción:** Se introduce el medicamento o medicamentos, y su dosis. Además, se añade la frecuencia con la que debe tomarlos y el comienzo y fin de dicho tratamiento, y lo asigna a un paciente previamente seleccionado.

**Actores principales:** Clínica.

**Precondiciones:**

* Seleccionar previamente a un paciente.

**Flujo principal:**

1. El administrador quiere asignarle un tratamiento a un paciente.
2. El administrador selecciona al paciente.
3. El administrador introduce los datos del tratamiento asignado.
4. El administrador muestra por pantalla al paciente actualizado y muestra un mensaje si dicha actualización se realizó correctamente.

**Postcondiciones:**

* Ninguna.

**Flujos alternativos:**

4.a. Si los datos se introdujeron mal, el sistema no actualiza al paciente e informa de dicho fallo.
