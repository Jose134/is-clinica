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
03. Añadir nuevo tratamiento a paciente
04. Añadir nueva entrada a historial de paciente
05. Mostrar citas
06. Mostrar lista con pacientes
07. Mostrar toda la información del paciente seleccionado
08. Modificar paciente
09. Modificar tratamiento
10. Búsqueda por nombre (opcional: busqueda por otros campos)
11. Borrar paciente
12. Mover cita
13. Cancelar cita
14. Consultar citas de hoy
15. Consultar citas de un paciente
16. Consultar historial médico de un paciente
17. Consultar tratamientos de un paciente

**No Funcionales:**
1. Sistema Operativo Linux
2. Los datos del historial no se pueden borrar
3. Los datos del tratamiento tampoco se pueden borrar una vez finalizado
