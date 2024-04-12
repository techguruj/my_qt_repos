use projekte;	--Öffne Datenbank


--drop database projekte;	--Lösche Datenbank


--create database projekte;	--Erzeuge Datenbank


-----------------Tabellen erzeugen--------------------
create table abteilung
(
	abt_nr char(2) not null primary key check(abt_nr like '[a-z][0-9]' ),
	abt_name varchar(20) not null,
	abt_stadt varchar(20) null	
);

create table projekt
(
	pr_nr char(2) not null primary key,
	pr_name varchar(20) not null,
	pr_mittel smallmoney null check (pr_mittel >0)
);
-------------------------------------------------Tabelle Mitarbeiter erzeugen---
create table mitarbeiter
(
	m_nr smallint not null primary key,
	m_name varchar(20) not null,
	m_vorname varchar(20) not null,
	m_abt_nr char(2),
	constraint for_abteilung 
		foreign key(m_abt_nr)
		references abteilung(abt_nr)
);
-------------------------------------------------Tabelle Arbeiten erzeugen---
create table arbeiten
(
	arb_m_nr smallint not null,
	arb_pr_nr char(2) not null,
	arb_aufgabe varchar(20) null,
	arb_einst_dat smalldatetime,
	constraint for_mit 
		foreign key(arb_m_nr)
		references mitarbeiter(m_nr),
	constraint for_pr
		foreign key(arb_pr_nr)
		references projekt(pr_nr),
	constraint pri_arb
		primary key(arb_m_nr, arb_pr_nr)
);

-----------------Indicees erzeugen--------------------
create index idx_m_nr
	on arbeiten(arb_m_nr);

create index idx_pr_nr
	on arbeiten(arb_pr_nr);

create index idx_abt_nr
	on mitarbeiter(m_abt_nr);

--Bsp:
--drop index idx_m_nr;  --wieder löschen

-----------------Struktur verändern-------------------
--Bsp:
/*alter table arbeiten
	add constraint for_mit 
		foreign key(arb_m_nr)
		references mitarbeiter(m_nr),
	    constraint for_pr
		foreign key(arb_pr_nr)
		references projekt(pr_nr),
	    constraint pri_arb
		primary key(arb_m_nr, arb_pr_nr);

--Zusätzliches Feld Telefon hinzufügen

--alter table mitarbeiter  
	--add telefon varchar(20) null;
--alter table mitarbeiter
	--drop column telefon;
--alter table mitarbeiter
	--modify --?Nur in einigen Datenbanksystem


*/