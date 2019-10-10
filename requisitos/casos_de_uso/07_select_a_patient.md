# Seleccionar a un paciente
**ID**: 07
**Descripción**: Se selecciona a un paciente por nombre y de los resultados que te salgan por pantalla, seleccionas uno en específico por número de telefono.

**Actores principales**: Clínica

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. Se desea buscar a un paciente para realizar una operación sobre él
2. El usuario introduce el nombre del paciente
3. El sistema muestra una lista con todos los pacientes cuyo nombre coincida con la búsqueda.
4. El usuario introduce el teléfono del paciente
5 El sistema selecciona ese paciente.

**Postcondiciones**:
* Se debe dar la opción de seleccionar uno de los pacientes encontrados

**Flujos alternativos**:
3.a. Si no se encuentra ningún paciente que coincida con el nombre introducido se mostrará un aviso
5.a. Si no se encuentra ningún paciente que coincida con el número de teléfono introducido se mostrará un aviso
 
