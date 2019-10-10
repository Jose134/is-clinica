# Añadir nueva entrada a historial de paciente

**ID:** 04

**Descripción:** Se introduce la fecha de consulta y los síntomas que tenía el paciente y lo asigna a un paciente previamente seleccionado.

**Actores principales:** Clínica.

**Precondiciones:**

* Seleccionar previamente a un paciente.

**Flujo principal:**

1. El administrador quiere asignarle historial a un paciente.
2. El administrador selecciona al paciente.
3. El administrador introduce los datos del historial.
4. El administrador muestra por pantalla al paciente actualizado y muestra un mensaje si dicha actualización se realizó correctamente.

**Postcondiciones:**

* Ninguna.

**Flujos alternativos:**

4.a. Si los datos se introdujeron mal, el sistema no actualiza al paciente e informa de dicho fallo.
