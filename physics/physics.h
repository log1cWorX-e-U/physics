#pragma once

/// \file physics.h
/// \brief Physikalische Konstanten, Bahnelemente des Sonnensystems und Kepler-/Weber-Bahnfunktionen.

#include <stdint.h>
#include <vector/vector.h>

/// \brief Lichtgeschwindigkeit im Vakuum in m/s.
#define PHYSICS_C 299792458.0L
/// \brief Gravitationskonstante G in m^3 kg^-1 s^-2.
#define PHYSICS_G 6.6743015e-11L
/// \brief Quadrat der Lichtgeschwindigkeit in m^2/s^2 (ausgeschrieben, um Rundungsfehler zu vermeiden).
#define PHYSICS_C_SQUARE (299792458.0L * 299792458.0L)
/// \brief Astronomische Einheit in Metern.
#define PHYSICS_AU 149597870700.0L
/// \brief Wellenlaenge des Calcium-K-Filters in Metern (393,3 nm).
#define PHYSICS_CALCIUM_FILTER_WAVELENGTH_M 393.3e-9L
/// \brief Wellenlaenge des gruenen Filters in Metern (540 nm).
#define PHYSICS_GREEN_FILTER_M 540.0e-9L

// https://www.imcce.fr/

/// \brief Masse der Sonne in kg.
#define PHYSICS_SUN_MASS 1.98841e30L
/// \brief Masse des Merkur in kg.
#define PHYSICS_MERCURY_MASS 3.301e23L
/// \brief Masse der Venus in kg.
#define PHYSICS_VENUS_MASS 4.8673e24L
/// \brief Masse der Erde in kg.
#define PHYSICS_EARTH_MASS 5.9722e24L
/// \brief Masse des Mondes in kg.
#define PHYSICS_MOON_MASS 7.346e22L
/// \brief Mittlere Anomalie des Mondes zur Epoche J2000.0 (Radiant).
/// \note Meeus: mittlere Laenge 218.3164477 - Perigaeum 83.3532465. Fehlte bis hierher ganz; die
///       uebrigen Bahndaten des Mondes waren die Werte der ERDE (Knoten 0, Perigaeum 102.937).
#define PHYSICS_MOON_M0 2.355552230L
/// \brief Masse des Mars in kg.
#define PHYSICS_MARS_MASS 6.417e23L
/// \brief Masse des Marsmondes Phobos in kg.
#define PHYSICS_MARS_PHOBOS_MASS 1.072e16L
/// \brief Masse des Marsmondes Deimos in kg.
#define PHYSICS_MARS_DEIMOS_MASS 1.8e15L
/// \brief Gesamtmasse des Mars-Systems (Mars + Phobos + Deimos) in kg.
#define PHYSICS_MARS_SYSTEM_MASS (PHYSICS_MARS_MASS + PHYSICS_MARS_PHOBOS_MASS + PHYSICS_MARS_DEIMOS_MASS)
/// \brief Masse des Jupiter in kg.
#define PHYSICS_JUPITER_MASS 1.89813e27L
/// \brief Masse des Jupitermondes Ganymed in kg.
#define PHYSICS_JUPITER_GANYMED_MASS 1.4819e23L
/// \brief Masse des Jupitermondes Kallisto in kg.
#define PHYSICS_JUPITER_KALLISTO_MASS 1.0759e23L
/// \brief Masse des Jupitermondes Europa in kg.
#define PHYSICS_JUPITER_EUROPA_MASS 4.800e22L
/// \brief Masse des Jupitermondes Io in kg.
#define PHYSICS_JUPITER_IO_MASS 8.93193797e22L
/// \brief Gesamtmasse des Jupiter-Systems (Jupiter + vier galileische Monde) in kg.
#define PHYSICS_JUPITER_SYSTEM_MASS (PHYSICS_JUPITER_MASS + PHYSICS_JUPITER_GANYMED_MASS + \
    PHYSICS_JUPITER_KALLISTO_MASS + PHYSICS_JUPITER_EUROPA_MASS + PHYSICS_JUPITER_IO_MASS)
/// \brief Masse des Saturn in kg.
#define PHYSICS_SATURN_MASS 5.683e26L
/// \brief Masse des Saturnmondes Titan in kg.
#define PHYSICS_SATURN_TITAN_MASS 1.345e23L
/// \brief Masse des Saturnmondes Rhea in kg.
#define PHYSICS_SATURN_RHEA_MASS 2.31e21L
/// \brief Masse des Saturnmondes Dione in kg.
#define PHYSICS_SATURN_DIONE_MASS 1.10e21L
/// \brief Masse des Saturnmondes Tethys in kg.
#define PHYSICS_SATURN_TETHYS_MASS 6.18e20L
/// \brief Masse des Saturnmondes Iapetus in kg.
#define PHYSICS_SATURN_IAPETUS_MASS 1.81e21L
/// \brief Gesamtmasse des Saturn-Systems (Saturn + fuenf Monde) in kg.
#define PHYSICS_SATURN_SYSTEM_MASS (PHYSICS_SATURN_MASS + PHYSICS_SATURN_TITAN_MASS + PHYSICS_SATURN_RHEA_MASS + \
    PHYSICS_SATURN_DIONE_MASS + PHYSICS_SATURN_TETHYS_MASS + PHYSICS_SATURN_IAPETUS_MASS)
/// \brief Masse des Uranus in kg.
#define PHYSICS_URANUS_MASS 8.681e25L
/// \brief Masse des Neptun in kg.
#define PHYSICS_NEPTUNE_MASS 1.024e26L

/// \brief Grosse Halbachse der Sonnenbahn in AU.
#define PHYSICS_SUN_A 0.0L
/// \brief Grosse Halbachse der Merkurbahn in AU.
#define PHYSICS_MERCURY_A 0.3870983098L
/// \brief Grosse Halbachse der Venusbahn in AU.
#define PHYSICS_VENUS_A 0.7233298200L
/// \brief Grosse Halbachse der Erdbahn in AU.
#define PHYSICS_EARTH_A 1.0000010178L
/// \brief Grosse Halbachse der Mondbahn in AU (384000 km umgerechnet).
#define PHYSICS_MOON_A (384400.0e3L / PHYSICS_AU)
/// \brief Grosse Halbachse der Marsbahn in AU.
#define PHYSICS_MARS_A 1.5236793419L
/// \brief Grosse Halbachse der Jupiterbahn in AU.
#define PHYSICS_JUPITER_A 5.2026032092L
/// \brief Grosse Halbachse der Saturnbahn in AU.
#define PHYSICS_SATURN_A 9.5549091915L
/// \brief Grosse Halbachse der Uranusbahn in AU.
#define PHYSICS_URANUS_A 19.2184460618L
/// \brief Grosse Halbachse der Neptunbahn in AU.
#define PHYSICS_NEPTUNE_A 30.1103868694L

/// \brief Numerische Exzentrizitaet der Sonnenbahn.
#define PHYSICS_SUN_ECCENTRICITY 0.0L
/// \brief Numerische Exzentrizitaet der Merkurbahn.
#define PHYSICS_MERCURY_ECCENTRICITY 0.2056317526L
/// \brief Numerische Exzentrizitaet der Venusbahn.
#define PHYSICS_VENUS_ECCENTRICITY 0.0067719164L
/// \brief Numerische Exzentrizitaet der Erdbahn.
#define PHYSICS_EARTH_ECCENTRICITY 0.0167086342L
/// \brief Numerische Exzentrizitaet der Mondbahn.
#define PHYSICS_MOON_ECCENTRICITY 0.0549L
/// \brief Numerische Exzentrizitaet der Marsbahn.
#define PHYSICS_MARS_ECCENTRICITY 0.0934006477L
/// \brief Numerische Exzentrizitaet der Jupiterbahn.
#define PHYSICS_JUPITER_ECCENTRICITY 0.0484979255L
/// \brief Numerische Exzentrizitaet der Saturnbahn.
#define PHYSICS_SATURN_ECCENTRICITY 0.0555481426L
/// \brief Numerische Exzentrizitaet der Uranusbahn.
#define PHYSICS_URANUS_ECCENTRICITY 0.0463812221L
/// \brief Numerische Exzentrizitaet der Neptunbahn.
#define PHYSICS_NEPTUNE_ECCENTRICITY 0.009455747L

/// \brief Bahnneigung (Inklination) der Sonnenbahn in Grad.
#define PHYSICS_SUN_I 0.0L
/// \brief Bahnneigung (Inklination) der Merkurbahn in Grad.
#define PHYSICS_MERCURY_I 7.00498625L
/// \brief Bahnneigung (Inklination) der Venusbahn in Grad.
#define PHYSICS_VENUS_I 3.39466189L
/// \brief Bahnneigung (Inklination) der Erdbahn in Grad.
#define PHYSICS_EARTH_I 0.0L
/// \brief Bahnneigung (Inklination) der Mondbahn in Grad.
#define PHYSICS_MOON_I 5.145L
/// \brief Bahnneigung (Inklination) der Marsbahn in Grad.
#define PHYSICS_MARS_I 1.84972648L
/// \brief Bahnneigung (Inklination) der Jupiterbahn in Grad.
#define PHYSICS_JUPITER_I 1.30326698L
/// \brief Bahnneigung (Inklination) der Saturnbahn in Grad.
#define PHYSICS_SATURN_I 2.48887878L
/// \brief Bahnneigung (Inklination) der Uranusbahn in Grad.
#define PHYSICS_URANUS_I 0.77319689L
/// \brief Bahnneigung (Inklination) der Neptunbahn in Grad.
#define PHYSICS_NEPTUNE_I 1.76995259L

/// \brief Aufsteigender Knoten
#define PHYSICS_SUN_NODE 0.0L
/// \brief Aufsteigender Knoten der Merkurbahn in Grad.
#define PHYSICS_MERCURY_NODE 48.33089304L
/// \brief Aufsteigender Knoten der Venusbahn in Grad.
#define PHYSICS_VENUS_NODE 76.67992019L
/// \brief Aufsteigender Knoten der Erdbahn in Grad.
#define PHYSICS_EARTH_NODE 0.0L
/// \brief Aufsteigender Knoten der Mondbahn in Grad.
#define PHYSICS_MOON_NODE 125.0445479L
/// \brief Aufsteigender Knoten der Marsbahn in Grad.
#define PHYSICS_MARS_NODE 49.55809321L
/// \brief Aufsteigender Knoten der Jupiterbahn in Grad.
#define PHYSICS_JUPITER_NODE 100.46440702L
/// \brief Aufsteigender Knoten der Saturnbahn in Grad.
#define PHYSICS_SATURN_NODE 113.66550252L
/// \brief Aufsteigender Knoten der Uranusbahn in Grad.
#define PHYSICS_URANUS_NODE 74.00595701L
/// \brief Aufsteigender Knoten der Neptunbahn in Grad.
#define PHYSICS_NEPTUNE_NODE 131.78405702L

/// \brief Perihellänge
#define PHYSICS_SUN_PL 0.0L
/// \brief Perihellänge der Merkurbahn in Grad.
#define PHYSICS_MERCURY_PL 77.45611904L
/// \brief Perihellänge der Venusbahn in Grad.
#define PHYSICS_VENUS_PL 131.56370300L
/// \brief Perihellänge der Erdbahn in Grad.
#define PHYSICS_EARTH_PL 102.93734808L
/// \brief Perihellänge der Mondbahn in Grad.
#define PHYSICS_MOON_PL 83.3532465L
/// \brief Perihellänge der Marsbahn in Grad.
#define PHYSICS_MARS_PL 336.06023395L
/// \brief Perihellänge der Jupiterbahn in Grad.
#define PHYSICS_JUPITER_PL 14.33120687L
/// \brief Perihellänge der Saturnbahn in Grad.
#define PHYSICS_SATURN_PL 93.05723748L
/// \brief Perihellänge der Uranusbahn in Grad.
#define PHYSICS_URANUS_PL 173.00529106L
/// \brief Perihellänge der Neptunbahn in Grad.
#define PHYSICS_NEPTUNE_PL 48.12027554L

/// \brief Mittlere Laenge (mean longitude) der Sonnenbahn in Grad.
#define PHYSICS_SUN_W 0.0L
/// \brief Mittlere Laenge der Merkurbahn in Grad.
#define PHYSICS_MERCURY_W 29.125226L
/// \brief Mittlere Laenge der Venusbahn in Grad.
#define PHYSICS_VENUS_W 54.88378281L
/// \brief Mittlere Laenge der Erdbahn in Grad.
#define PHYSICS_EARTH_W 100.46645683L
/// \brief Mittlere Laenge der Mondbahn in Grad.
#define PHYSICS_MOON_W 218.3164477L
/// \brief Mittlere Laenge der Marsbahn in Grad.
#define PHYSICS_MARS_W 286.50214074L
/// \brief Mittlere Laenge der Jupiterbahn in Grad.
#define PHYSICS_JUPITER_W 273.86679985L
/// \brief Mittlere Laenge der Saturnbahn in Grad.
#define PHYSICS_SATURN_W 339.39173496L
/// \brief Mittlere Laenge der Uranusbahn in Grad.
#define PHYSICS_URANUS_W 98.99933405L
/// \brief Mittlere Laenge der Neptunbahn in Grad.
#define PHYSICS_NEPTUNE_W 276.33621852L

/// \brief Mittlere Anomalie M0 zur Epoche J2000.0 (in Radiant).
/// \note Quelle: IMCCE VSOP87 (https://www.imcce.fr). Die vier AEUSSEREN Planeten stammen aus den
///       J2000-Mittelbahnen (JPL / Explanatory Supplement, Tab. 5.8.1): die frueheren Werte waren um
///       77 bis 244 Grad falsch — die Planeten standen damit sichtbar an der falschen Stelle.
///       Es gilt M0 = mittlere Laenge L - Perihellänge.
#define PHYSICS_MERCURY_M0   3.050L          ///< VSOP87: 174.793° (Merkur)
#define PHYSICS_VENUS_M0     0.880L          ///< VSOP87: 50.416°  (Venus)
#define PHYSICS_EARTH_M0     6.240L          ///< VSOP87: 357.517° (Erde)
#define PHYSICS_MARS_M0      0.338L          ///< VSOP87: 19.373°  (Mars)
#define PHYSICS_JUPITER_M0   0.350342962L    ///< 20.07317° (J2000: mittlere Laenge 34.40438° - Perihellänge 14.33121°)
#define PHYSICS_SATURN_M0   5.530722947L    ///< 316.88708° (J2000: mittlere Laenge 49.94432° - Perihellänge 93.05724°)
#define PHYSICS_URANUS_M0   2.447420912L    ///< 140.22689° (J2000: mittlere Laenge 313.23218° - Perihellänge 173.00529°)
#define PHYSICS_NEPTUNE_M0   4.481303102L    ///< 256.75975° (J2000: mittlere Laenge 304.88003° - Perihellänge 48.12028°)

/// \brief Ein Himmelskoerper samt Zustandsvektoren und abgeleiteten Bahngroessen.
typedef struct celestial_body
{
    struct vector_3d r_m;        ///< Ortsvektor im heliozentrischen System in Metern.
    struct vector_3d r_bary_m;   ///< Baryzentrischer Ortsvektor in Metern.
    struct vector_3d v_m_s;      ///< Geschwindigkeitsvektor in m/s.
    struct vector_3d v_bary_m_s; ///< Baryzentrische Geschwindigkeit in m/s.
    struct vector_3d w_rad_s;    ///< Winkelgeschwindigkeitsvektor in rad/s.
    ld h;                        ///< Spezifischer Drehimpuls (Weber), siehe physics_weber_h.
    ld K;                        ///< Weber-Korrekturfaktor der Bahn, siehe physics_weber_k.
    ld mass_kg;                  ///< Masse des Koerpers in kg.
    ld e;                        ///< Numerische Exzentrizitaet der Bahn.
    ld e_square;                 ///< Quadrat der Exzentrizitaet (e * e).
    ld a_m;                      ///< Grosse Halbachse der Bahn in Metern.
    ld T_a;                      ///< Umlaufzeit in Jahren (a).
    ld perihel_m;                ///< Periheldistanz in Metern.
    ld perihel_arc_s;            ///< Periheldrehung pro Umlauf in Radiant (zur Anzeige in Bogensekunden umgerechnet).
    const char* name;            ///< Anzeigename des Koerpers.
    uint32_t index;              ///< Laufindex des Koerpers.
} *celestial_body_t;

/// \brief Kreiszahl Pi.
/// \return Pi als long double.
ld physics_pi();

/// \brief Nachkommaanteil einer Zahl (x - floor(x)).
/// \param x Zahl.
/// \return Nachkommaanteil, immer in [0, 1).
ld physics_frac(cld x);

/// \brief Echter Modulo, Ergebnis immer nicht-negativ.
/// \param a Dividend.
/// \param b Divisor (ungleich 0).
/// \return Rest b * frac(a / b) in [0, b).
ld physics_modulo(cld a, cld b);

/// \brief Wandelt Grad in Radiant um.
/// \param angle_deg Winkel in Grad.
/// \return Winkel in Radiant.
ld physics_deg_to_rad(cld angle_deg);

/// \brief Wandelt Radiant in Grad um.
/// \param angle_rad Winkel in Radiant.
/// \return Winkel in Grad.
ld physics_rad_to_deg(cld angle_rad);

/// \brief Anzahl der Sekunden eines Erdjahres, aus der Weber-Umlaufzeit der Erde.
/// \return Laenge eines Jahres in Sekunden.
ld physics_seconds_per_year();

/// \brief Abstand des Baryzentrums vom Mittelpunkt in Astronomischen Einheiten.
/// \param distance_AU Abstand beider Koerper in AU.
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \param mass_satellite_kg Masse des Begleiters in kg.
/// \return Abstand des Baryzentrums vom Zentralkoerper in AU.
ld physics_barycenter_AU(cld distance_AU, cld mass_center_kg, cld mass_satellite_kg);

/// \brief Rayleigh-Auflaesungsgrenze eines optischen Systems in Grad.
/// \param wavelength_light_m Wellenlaenge des Lichts in Metern.
/// \param objective_aperture_m Oeffnung (Apertur) des Objektivs in Metern.
/// \return Kleinster aufloesbarer Winkel in Grad.
ld physics_rayleigh_criteria_deg(cld wavelength_light_m, cld objective_aperture_m);

/// \brief Abbildungsgroesse eines Objekts auf dem Sensor in Metern.
/// \param object_size_deg Winkeldurchmesser des Objekts in Grad.
/// \param focal_length_m Brennweite in Metern.
/// \return Groesse des Bildes auf dem Sensor in Metern.
ld physics_image_sensor_object_size_m(cld object_size_deg, cld focal_length_m);

/// \brief Kleinste noetige Sensorpixelgroesse, um ein Objekt an der Auflaesungsgrenze abzubilden.
/// \param wavelength_light_m Wellenlaenge des Lichts in Metern.
/// \param objective_aperture_m Oeffnung des Objektivs in Metern.
/// \param focal_length_m Brennweite in Metern.
/// \return Noetige Pixelgroesse in Metern (halbe Beugungsscheibengroesse).
ld physics_needed_image_sensor_pixel_size_m(cld wavelength_light_m, cld objective_aperture_m, cld focal_length_m);

/// \brief Radius einer Kepler-Bahn beim Winkel phi.
/// \param a_m Grosse Halbachse in Metern.
/// \param eccentricity Numerische Exzentrizitaet.
/// \param phi_rad Wahre Anomalie in Radiant.
/// \return Abstand zum Brennpunkt in Metern.
/// \note Die Bahnkurve ist eine Ellipse mit dem Zentralkoerper in einem Brennpunkt.
ld physics_kepler_radius(cld a_m, cld eccentricity, cld phi_rad);

/// \brief Kinetische Energie aus Masse und Geschwindigkeitsvektor.
/// \param mass_kg Masse in kg.
/// \param v Geschwindigkeitsvektor in m/s.
/// \return Kinetische Energie in Joule.
ld physics_kinetic_energy(cld mass_kg, const vector_3d_t v);

/// \brief Kinetische Energie eines Himmelskoerpers.
/// \param body Himmelskoerper; genutzt werden mass_kg und v_m_s.
/// \return Kinetische Energie in Joule.
ld physics_kinetic_energy_body(const celestial_body_t body);

/// \brief Spezifischer Drehimpuls h einer Weber-Bahn.
/// \param body Himmelskoerper (a_m, e_square).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Spezifischer Drehimpuls in m^2/s.
ld physics_weber_h(const celestial_body_t body, cld mass_center_kg);

/// \brief Weber-Parameter alpha (relativistische Korrektur der Periheldrehung).
/// \param body Himmelskoerper (h, e).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Dimensionsloser Parameter alpha.
/// \note Setzt voraus, dass body->h bereits mit physics_weber_h gesetzt wurde.
ld physics_weber_alpha(const celestial_body_t body, cld mass_center_kg);

/// \brief Weber-Korrekturfaktor K der Bahn (K < 1, veraendert die Winkelpha).
/// \param body Himmelskoerper (a_m, e_square).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Korrekturfaktor K.
ld physics_weber_k(const celestial_body_t body, cld mass_center_kg);

/// \brief Umlaufzeit einer Weber-Bahn.
/// \param body Himmelskoerper (a_m, e_square).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Umlaufzeit in Sekunden.
ld physics_weber_periodtime(const celestial_body_t body, cld mass_center_kg);

/// \brief Zuwachs des Bahnwinkels phi ueber ein Zeitintervall.
/// \param body Himmelskoerper (siehe physics_weber_angular_speed).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \param t_step_s verstrichene Zeit in Sekunden.
/// \param phi_0_rad Startwinkel in Radiant.
/// \return Differenzwinkel in Radiant.
ld physics_weber_deltaphi(const celestial_body_t body, cld mass_center_kg, cld t_step_s, cld phi_0_rad);

/// \brief Numerisch integrierter Winkelzuwachs der Weber-Bahn (GSL-ODE).
/// \param body Himmelskoerper.
/// \param phi_0_rad Startwinkel in Radiant.
/// \param T_0_s Startzeit in Sekunden.
/// \param T_step_s Endzeit in Sekunden.
/// \return Differenzwinkel phi - phi_0 in Radiant.
/// \note Integriert dphi/dt = h / r^2 mit einem Runge-Kutta-Fehlberg-Löser (rkf45). Die
///       Integration geht immer um die Sonne (PHYSICS_SUN_MASS).
ld physics_weber_delta_phi_ode(const celestial_body_t body, ld phi_0_rad, ld T_0_s, ld T_step_s);

/// \brief Periheldrehung pro Umlauf.
/// \param body Himmelskoerper (K).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Differenzwinkel pro Umlauf in Radiant.
ld physics_deltaphi_per_revolution(const celestial_body_t body, cld mass_center_kg);

/// \brief Umlaufzeit einer Weber-Bahn.
/// \param body Himmelskoerper (a_m, e_square).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \return Umlaufzeit in Sekunden.
ld physics_weber_periodtime(const celestial_body_t body, cld mass_center_kg);

/// \brief Bahnposition eines Koerpers auf der Weber-Bahn beim Winkel phi.
/// \param body Himmelskoerper (a_m, e, e_square, K).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \param phi_rad Bahnwinkel in Radiant.
/// \return Positionsvektor in Metern.
struct vector_3d physics_weber_position(const celestial_body_t body, cld mass_center_kg, cld phi_rad);

/// \brief Winkelgeschwindigkeit eines Koerpers auf der Weber-Bahn.
/// \param body Himmelskoerper (h, a_m, e, e_square, K).
/// \param mass_center_kg Masse des Zentralkoerpers in kg.
/// \param phi_rad Bahnwinkel in Radiant.
/// \return Winkelgeschwindigkeitsvektor in rad/s (nur z-Komponente belegt).
struct vector_3d physics_weber_angular_speed(const celestial_body_t body, cld mass_center_kg, cld phi_rad);
