/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:07:59 by jeberle           #+#    #+#             */
/*   Updated: 2026/10/19 17:18:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

int	prepare_step(t_ping *ping)
{
	(void)ping;
	// 1. Entferne (void)ping, sobald die Funktion ping verwendet.
	// 2. Ergaenze in t_ping Speicher fuer Paket, Paketlaenge, Sequenznummer und Sendezeit.
	// 3. Erstelle ein ICMP-Echo-Request-Paket: Typ ICMP_ECHO und Code 0.
	// 4. Setze Kennung und Sequenznummer, damit du die Antwort zuordnen kannst.
	// 5. Schreibe einen Payload mit Daten, die in der Antwort wiedererkannt werden.
	// 6. Berechne die Pruefsumme ueber den gesamten ICMP-Header und den Payload.
	// 7. Speichere die Sendezeit in ping fuer die spaetere RTT-Berechnung.
	// 8. Gib bei Erfolg 0 und bei einem Fehler einen Fehlerwert zurueck.
	return (0);
}

int	send_ping(t_ping *ping)
{
	(void)ping;
	// 1. Entferne (void)ping, sobald die Funktion ping verwendet.
	// 2. Sende das vorbereitete Paket mit sendto() ueber ping->socket_fd.
	// 3. Verwende ping->resolved_addr als Zieladresse.
	// 4. Pruefe auf sendto()-Fehler und ob die erwartete Bytezahl gesendet wurde.
	// 5. Gib bei Erfolg 0 und bei einem Fehler einen Fehlerwert zurueck.
	return (0);
}

int	receive_ping(t_ping *ping)
{
	(void)ping;
	// 1. Entferne (void)ping, sobald die Funktion ping verwendet.
	// 2. Lege einen Puffer fuer IP-Header und ICMP-Paket an.
	// 3. Setze ein Empfangs-Timeout, damit recvfrom() nicht endlos wartet.
	// 4. Empfange mit recvfrom() und pruefe, ob ein Fehler aufgetreten ist.
	// 5. Bestimme die IP-Header-Laenge: Der ICMP-Header folgt erst danach.
	// 6. Pruefe ICMP_ECHOREPLY, Quelladresse, Kennung und Sequenznummer.
	// 7. Ignoriere nicht passende Pakete oder behandle ICMP-Fehler passend.
	// 8. Berechne die RTT aus Sendezeit und aktueller Empfangszeit.
	// 9. Gib die echte Antwort mit Host, Sequenznummer, TTL und RTT aus.
	// 10. Gib bei Erfolg 0 und bei einem Fehler einen Fehlerwert zurueck.
	return (0);
}
