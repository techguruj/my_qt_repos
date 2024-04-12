--------------------------------------------------------------------- Datenbank anlegen und aktivieren

create database EE_projekte3;
go -- Synchronisieren
use EE_projekte3;

--------------------------------------------------------------------- Struktur für Tabellen

CREATE TABLE abteilung (
  abt_nr char(2) NOT NULL primary key,
  abt_name varchar(20) NOT NULL,
  abt_stadt varchar(20) DEFAULT NULL
) ;

CREATE TABLE mitarbeiter (
  m_nr smallint not null primary key ,
  m_name varchar(20) NOT NULL,
  m_vorname varchar(20) NOT NULL,
  m_abt_nr char(2) NULL,
  constraint for_abt foreign key(m_abt_nr) references abteilung(abt_nr)
);

CREATE TABLE mitarbeiterdaten (
  ma_nr smallint NOT NULL primary key,
  ma_gehalt decimal(10,2) NULL,
  ma_steuerklasse tinyint NULL,
  ma_rv_nr varchar(15) NULL,
  ma_kk varchar(15) NULL,
  constraint for_mit_in_mitdat foreign key(ma_nr) references mitarbeiter(m_nr)
);

CREATE TABLE projekt (
  pr_nr char(2) NOT NULL primary key,
  pr_name varchar(20) NOT NULL,
  pr_mittel decimal(10,2) NULL CHECK (pr_mittel > 0)
);
go
CREATE TABLE arbeiten (
  arb_m_nr smallint NOT NULL,
  arb_pr_nr char(2) NOT NULL,
  arb_aufgabe varchar(20) NULL,
  arb_einst_dat date NULL
  constraint pri_arb primary key(arb_m_nr, arb_pr_nr), -- Zusammengesetzten Primärschlüssel setzen
  constraint for_mit_in_Prj foreign key(arb_m_nr) references mitarbeiter(m_nr),
  constraint for_prj foreign key(arb_pr_nr) references projekt(pr_nr)
); 

--------------------------------------------------------------------- Index auf Fremdschlüssel setzen
create index ind_abt on mitarbeiter(m_abt_nr);  
create index ind_ma on mitarbeiterdaten(ma_nr);
create index ind_arb_mit on arbeiten(arb_m_nr);
create index ind_arb_pr on arbeiten(arb_pr_nr);

--------------------------------------------------------------------- Daten für Tabellen

INSERT INTO abteilung (abt_nr, abt_name, abt_stadt) 
VALUES
('a1', 'Beratung', 'München'),
('a2', 'Diagnose', 'München'),
('a3', 'Freigabe', 'Stuttgart'),
('a4', 'Testverfahren', 'Stuttgart'),
('a5', 'Dokumentation', 'Stuttgart'),
('a6', 'Entwicklung', 'München'),
('a7', 'Marketing', 'Frankfurt'),
('a8', 'Buchhaltung', 'Frankfurt'),
('a9', 'Personal', NULL);

INSERT INTO mitarbeiter (m_nr, m_name, m_vorname, m_abt_nr) VALUES
(2581, 'Kaufmann', 'Brigitte', 'a2'),
(7437, 'Förster', 'Georg', 'a4'),
(9031, 'Meier', 'Rainer', 'a2'),
(10102, 'Huber', 'Petra', 'a3'),
(14326, 'Jäger', 'Uwe', 'a4'),
(17243, 'Meier', 'Paul', 'a5'),
(17437, 'Schenk', 'Walter', 'a6'),
(18316, 'Müller', 'Gabriele', 'a1'),
(19439, 'Köhler', 'Paul', 'a6'),
(20000, 'Schreiner', 'Petra', 'a9'),
(22596, 'Ziemann', 'Walter', 'a5'),
(22900, 'Schreiner', 'Ben', 'a9'),
(24377, 'Bauer', 'Rita', 'a7'),
(25348, 'Keller', 'Hans', 'a3'),
(27562, 'Schumacher', 'Eva', 'a7'),
(27859, 'Walter', 'Fritz', 'a7'),
(28559, 'Mozer', 'Sibille', 'a1'),
(29346, 'Probst', 'Andreas', 'a2'),
(30000, 'Lloyd', 'Herald', 'a9'),
(31132, 'Krüger', 'Sina', 'a4'),
(32000, 'Schneider', 'Horst', NULL);

INSERT INTO mitarbeiterdaten (ma_nr, ma_gehalt, ma_steuerklasse, ma_rv_nr, ma_kk) VALUES
(2581, '2860.00', 5, '29111964', 'Barmer'),
(9031, '4510.00', 3, '31081969', 'AOK'),
(10102, '1870.00', 1, '23091945', 'AOK'),
(14326, '2750.00', 1, '19082001', 'Barmer'),
(17243, '4100.00', 3, '01021978', 'BKK'),
(17437, '2600.00', 2, '27112000', 'AOk'),
(18316, '3630.00', 2, '23121967', 'BEK Mobil'),
(19439, '3800.00', 3, '14041976', 'TKK'),
(20000, '3450.00', 4, '24071993', 'BKK Mobil'),
(22900, '4250.00', 3, '31031988', 'AOK'),
(25348, '3080.00', 3, '12041984', 'Barmer'),
(27859, '2640.00', 1, '2031989', 'TKK'),
(28559, '2090.00', 5, '28101993', 'TKK'),
(29346, '2750.00', 1, '35111979', 'AOK'),
(30000, '3630.00', 1, '18061967', 'Barmer'),
(31132, '1800.00', 1, '17092003', 'Barmer'),
(32000, '1870.00', 2, '29022000', 'AOK');

INSERT INTO projekt (pr_nr, pr_name, pr_mittel) VALUES
('p1', 'Apollo', '120000.00'),
('p2', 'Gemini', '95000.00'),
('p3', 'Merkur', '186500.00'),
('p4', 'Pluto', '145000.00'),
('p5', 'Mars', '324400.00');

INSERT INTO arbeiten (arb_m_nr, arb_pr_nr, arb_aufgabe, arb_einst_dat) VALUES
(2581, 'p3', 'Projektleiter', '2020-10-15'),
(9031, 'p1', 'Gruppenleiter', '2020-04-15'),
(9031, 'p3', 'Sachbearbeiter', '2019-10-15'),
(10102, 'p3', 'Gruppenleiter', '2020-01-01'),
(18316, 'p2', NULL, '2020-06-01'),
(25348, 'p2', 'Sachbearbeiter', '2019-02-15'),
(28559, 'p1', NULL, '2019-08-01'),
(28559, 'p2', 'Sachbearbeiter', '2020-02-01'),
(29346, 'p1', 'Sachbearbeiter', '2020-04-01'),
(29346, 'p2', NULL, '2018-12-15');

