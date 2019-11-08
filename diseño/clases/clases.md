[Diagrama de Clases](ClassDiagram.jpg)

## Paciente
**Clase:** Paciente
**Descripción:** Contiene toda la información de un paciente
**Datos:**

 * nombreCompleto string; Nombre y Apellidos del paciente
 * telefono int; Teléfono de contacto del paciente
 * codigoPostal int; Código postal de la zona de residencia del paciente
 * fechaNacimiento string; Fecha de nacimiento del paciente
 * procedencia Procedencia; Tipo de procedencia del paciente
 * historial list<History>; Historial del paciente
 * tratamiento Treatment; Tratamiento activo del paciente
 * cita list<Cita>; Citas concertadas del paciente
 * DNI string; DNI del paciente

**Métodos:**

 * addCita - Añade una cita al paciente
 * endTratamiento - Finaliza el tratamiento actual del paciente, dejando el campo a null
 * getters y setters


## FileIO
**Clase:** FileIO
**Descripción:** Se encarga de obtener y guardar los pacientes comunicándose con los archivos de la aplicación 
**Datos:**

 * path string; Ruta donde buscará y guardará los archivos

**Métodos:**

 * exists - Comprueba si existe un paciente específico
 * getPatient - Busca en el archivo a un paciente específico
 * getAllPatients - Devuelve una lista con todos los pacientes
 * getAllAppointments -exists - Comprueba si existe un paciente específico
 * getPatient - Busca en el archivo a un paciente específico
 * getAllPatients - Devuelve una lista con todos los pacientes
 * getAllAppointments - Devuelve una lista con todas las citas de los pacientes
 * getTodayAppointments - Devuelve una lista con las citas para el día actual
 * savePatientData - Guarda los datos de un paciente Devuelve una lista con todas las citas de los pacientes
 * getTodayAppointments - Devuelve una lista con las citas para el día actual
 * savePatientData - Guarda los datos de un paciente
 * getters y setters


## Cita
**Clase:** Cita
**Descripción:** Almacena la información de una cita concertada de un paciente
**Datos:**

 * fecha string; Fecha de la cita
 * hora string; Hora de la cita
 * duración int; Duración de la cita (en minutos)

**Métodos:**

 * getters y setters

## History
**Clase:** History
**Descripción:** Almacena la información de una entrada al historial
**Datos:**

 * fecha string; Fecha en la que se añadió la entrada
 * sintomas string; Síntomas del paciente

**Métodos:**

 * getters y setters

## Treatment
**Clase:** Treatment
**Descripción:** Almacena los datos del tratamiento de un paciente
**Datos:**

 * medicamente string; Medicamente recetado al paciente
 * dosis int; Dosis del medicamente (en miligramos)
 * frecuencia int; Frecuencia con la que se debe tomar el medicamente (en horas)
 * comienzo string; Fecha de comienzo del tratamiento
 * fin string; Fecha de finalización del tratamiento

**Métodos:**

 * getters y setters
