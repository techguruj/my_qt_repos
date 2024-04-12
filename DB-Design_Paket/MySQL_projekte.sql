-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 15. Nov 2021 um 15:06
-- Server-Version: 10.4.21-MariaDB
-- PHP-Version: 8.0.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `projekte`
--
create database projekte;
use projekte;
-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `abteilung`
--

CREATE TABLE `abteilung` (
  `abt_nr` char(2) NOT NULL,
  `abt_name` varchar(20) NOT NULL,
  `abt_stadt` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `abteilung`
--

INSERT INTO `abteilung` (`abt_nr`, `abt_name`, `abt_stadt`) 
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

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `arbeiten`
--

CREATE TABLE `arbeiten` (
  `arb_m_nr` smallint(6) NOT NULL,
  `arb_pr_nr` char(2) NOT NULL,
  `arb_aufgabe` varchar(20) DEFAULT NULL,
  `arb_einst_dat` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `arbeiten`
--

INSERT INTO `arbeiten` (`arb_m_nr`, `arb_pr_nr`, `arb_aufgabe`, `arb_einst_dat`) VALUES
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

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `mitarbeiter`
--

CREATE TABLE `mitarbeiter` (
  `m_nr` smallint(6) NOT NULL,
  `m_name` varchar(20) NOT NULL,
  `m_vorname` varchar(20) NOT NULL,
  `m_abt_nr` char(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `mitarbeiter`
--

INSERT INTO `mitarbeiter` (`m_nr`, `m_name`, `m_vorname`, `m_abt_nr`) VALUES
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

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `mitarbeiterdaten`
--

CREATE TABLE `mitarbeiterdaten` (
  `ma_nr` smallint(6) NOT NULL,
  `ma_gehalt` decimal(10,2) DEFAULT NULL,
  `ma_steuerklasse` tinyint(4) DEFAULT NULL,
  `ma_rv_nr` varchar(15) DEFAULT NULL,
  `ma_kk` varchar(15) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `mitarbeiterdaten`
--

INSERT INTO `mitarbeiterdaten` (`ma_nr`, `ma_gehalt`, `ma_steuerklasse`, `ma_rv_nr`, `ma_kk`) VALUES
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
(31000, '4510.00', 3, '2052001', 'AOK'),
(31132, '1800.00', 1, '17092003', 'Barmer'),
(32000, '1870.00', 2, '29022000', 'AOK');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `projekt`
--

CREATE TABLE `projekt` (
  `pr_nr` char(2) NOT NULL,
  `pr_name` varchar(20) NOT NULL,
  `pr_mittel` decimal(10,2) DEFAULT NULL CHECK (`pr_mittel` > 0)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `projekt`
--

INSERT INTO `projekt` (`pr_nr`, `pr_name`, `pr_mittel`) VALUES
('p1', 'Apollo', '120000.00'),
('p2', 'Gemini', '95000.00'),
('p3', 'Merkur', '186500.00'),
('p4', 'Pluto', '145000.00'),
('p5', 'Mars', '324400.00');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `abteilung`
--
ALTER TABLE `abteilung`
  ADD PRIMARY KEY (`abt_nr`);

--
-- Indizes für die Tabelle `arbeiten`
--
ALTER TABLE `arbeiten`
  ADD PRIMARY KEY (`arb_m_nr`,`arb_pr_nr`),
  ADD KEY `for_pr` (`arb_pr_nr`);

--
-- Indizes für die Tabelle `mitarbeiter`
--
ALTER TABLE `mitarbeiter`
  ADD PRIMARY KEY (`m_nr`),
  ADD KEY `ind_mitarbeiter_abt_nr` (`m_abt_nr`);

--
-- Indizes für die Tabelle `mitarbeiterdaten`
--
ALTER TABLE `mitarbeiterdaten`
  ADD PRIMARY KEY (`ma_nr`);

--
-- Indizes für die Tabelle `projekt`
--
ALTER TABLE `projekt`
  ADD PRIMARY KEY (`pr_nr`);

--
-- Constraints der exportierten Tabellen
--

--
-- Constraints der Tabelle `arbeiten`
--
ALTER TABLE `arbeiten`
  ADD CONSTRAINT `for_mit` FOREIGN KEY (`arb_m_nr`) REFERENCES `mitarbeiter` (`m_nr`),
  ADD CONSTRAINT `for_pr` FOREIGN KEY (`arb_pr_nr`) REFERENCES `projekt` (`pr_nr`);

--
-- Constraints der Tabelle `mitarbeiter`
--
ALTER TABLE `mitarbeiter`
  ADD CONSTRAINT `for_abteilung` FOREIGN KEY (`m_abt_nr`) REFERENCES `abteilung` (`abt_nr`);
COMMIT;

alter table mitarbeiterdaten 
add CONSTRAINT for_mitarbeiter FOREIGN key(ma_nr) references mitarbeiter(m_nr);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
