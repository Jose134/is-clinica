# Extracción de requisitos

### Partes interesadas:
* Clínica Médica
* Desarrolladores del Grupo 30

### Datos que se deben almacenar:
> **Pacientes:** 
 * Nombre y Apellidos
 * Teléfono
 * Código Postal
 * Fecha Nacimiento
 * Procedencia (Privado/Empresa o Seguro)
 * Citas
 * Histoial
 * Tratamiento
 
> **Citas:**
 *  Día
 *  Hora
 *  Duración

>**Historial:**
 *  Fecha de consulta
 *  Síntoma

> **Tratamiento:**
 *  Medicamento
 *  Dosis
 *  Frecuencia
 *  Comienzo
 *  Fin
### Requisitos

**Funcionales:**
01. Añadir nuevo paciente
02. Añadir nueva cita
03. Añadir tratamiento a paciente
04. Añadir nueva entrada a historial de paciente
05. Mostrar citas
06. Mostrar lista con usuarios
07. Seleccionar un usuario
08. Mostrar toda la información del paciente seleccionado
09. Modificar paciente
10. Modificar tratamiento
11. Búsqueda por nombre (opcional: busqueda por otros campos)

**No Funcionales:**
1. Sistema Operativo Linux
2. Los datos del historial no se pueden borrar
3. Los datos del tratamiento tampoco se pueden borrar una vez finalizado
