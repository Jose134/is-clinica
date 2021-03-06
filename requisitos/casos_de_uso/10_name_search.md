# Búsqueda de paciente por nombre

**ID**: 10

**Descripción**: Se busca a un paciente por nombre y se muestran en pantalla todos los pacientes encontrados, pudiendo el administrador seleccionar uno de ellos.

**Actores principales**: Clínica

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El administrador desea buscar a un paciente para realizar una operación sobre él.
2. El administrador introduce el nombre del paciente.
3. El sistema muestra una lista con todos los pacientes cuyo nombre coincida con la búsqueda.

**Postcondiciones**:
* Se debe dar la opción de seleccionar uno de los pacientes encontrados.

**Flujos alternativos**:
3.a. Si no se encuentra ningún paciente que coincida con la búsqueda se mostrará un aviso.
