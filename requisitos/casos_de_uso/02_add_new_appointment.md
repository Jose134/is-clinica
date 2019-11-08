# Añadir nueva cita

**ID**: 02

**Descripción**: Se introduce la hora de comienzo y la duración y se asigna la cita a un paciente previamente seleccionado.

**Actores principales**: Clínica

**Precondiciones**:
* Seleccionar previamente a un paciente.

**Flujo principal**:
1. El administrador desea concertar una cita con un paciente.
2. El administrador selecciona un paciente.
3. El administrador elige la opcion de concertar cita.
4. El administrador introducen los datos de la cita.
5. El sistema añade la cita al paciente.

**Postcondiciones**:
* Ninguna.

**Flujos alternativos**:
5.a. Si los datos de la cita se introducen incorrectamente, no se añade y se muestra un mensaje de error.
5.b. Si la cita se solapa con otra ya existente se mostrará un mensaje de confirmación antes de añadirla.
