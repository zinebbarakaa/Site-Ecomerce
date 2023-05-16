<?php 
session_start();
include "connexion_BD/connexion.php";
include "panier.class.php";
if(isset($_SESSION['id']) && isset($_SESSION['nom']) && isset($_SESSION['prenom']) && isset($_SESSION['tel']))

{
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Facture</title>
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<style type="text/css">
		.livraison,.paiement{
			margin: 15px auto;
			width: 75vw;
			background-color:#fff ;
			border-radius: 10px;
			padding: 10px;
		}
		table {
			
			margin:15px auto;
			width: 70vw;
			}
		table tr th {
			width: 200px;
			height: 75px;
			text-align: center;
			font-size: 20px;
		}
		 table,tr {
        
        border: 1px solid  #f2f2f2;
        border-collapse: collapse;
      	}
      input {
      	outline: none;
      	}
		table tr td {
			height: 75px;
			font-size: 20px;
			padding-left: 20px;
		}
		.inpt,.Ville {
			width: 300px;
			margin-top: 10px;
			margin-bottom: 10px;
		}
		.ville {
			font-size: 20px;
			
		}
		select {
			height: 25px;
		}
		 .submit {

			width: 65vw;
			height: 40px;
			font-size: 15px;
			font-weight: bold;
			border: none;
			text-align: center;
			color: #fff;
			cursor: pointer;
			background-color:#D98880  ;

		}
		.adresse {
			width: 65vw;
			height: 70px;
			margin-bottom: 10px;
			margin-top: 10px;
		}
		table caption {
			padding: 10px;
			font-size: 20px;
		}
		label{
			font-size: 15px;
			color: #6C5957;
		}
		input .adresse::placeholder{
			text-align: top;
		}
		.Etape{
			font-size: 20px;
		}
		
	</style>
</head>
<body bgcolor="#f2f2f2">
<div class="livraison">

<form action="paiement.php" method="POST">
	<table>
	<caption>FINALISATION DE LA COMMANDE</caption>
	<tr>
		<td colspan="2" class="Etape"><i class="fas fa-check-circle" style="color:#99A8A6;"></i> 1.Adresse de livraison </td>
	</tr>
	<tr>
		<td >
			<div>
				<label>Prénom *</label>
			</div>
			<div>
				<input type="text" name="prenom" class="inpt" value='<?php echo $_SESSION['prenom']; ?>'>
			</div>
		</td>
		<td>
			<div>
				<label>Nom *</label>
			</div>
			<div>	
				<input type="text" name="nom" class="inpt"  value='<?php echo $_SESSION['nom']; ?>'>
			</div>
		</td>
	</tr>
	<tr>
		<td colspan="2">
			<div>
				<label>Numéro de téléphone mobile *</label>
			</div>
			<div>
				<input type="text" name="" value="+212" style="width:40px;text-align: center;">
				<input type="text" name="tel" class="inpt" style="width:245px;"  value='<?php echo $_SESSION['tel']; ?>'>
			</div>
		</td>
	</tr>
	<tr>
		<td colspan="2">
			<div>
				<label>Adresse *</label>
			</div>
			<div><input type="textarea" name="Adresse" placeholder=" Entrer Rue / Appartement / Suite / bloc / Batiment" class="adresse">
			</div>
		</td>
	</tr>
	<tr>
		<td colspan="2">
			<div>
				<label>Ville de Laivraison *</label>
			</div>
			<div>	
				<select  class="Ville" name="Ville">
					<?php

					$req="exec ps_Ville_Laivraison";
					$res=sqlsrv_query($conn,$req);
					while($row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC))
						{
							echo '<option value="'.$row['NomVille'].'">'.$row['NomVille'].'</option>';
						}

					?>
				
				</select>	
					
			</div>		
		</td>
	</tr>
	<tr>
		<td colspan="2">
			<input type="submit" class="submit" name="submit" value="ENREGISTRER">
		</td>
	</tr>
</table>
</form>
</div>
<div class="paiement">
	<table>
		<tr>
			<td colspan="2" class="Etape">
				<i class="fas fa-check-circle" style="color:#99A8A6;">
				</i> 
				2.Mode de paiement
			</td>
		</tr>
	</table>
	
</div>
</body>
</html>


<?php
include 'footer.php';
}

else {
	header("Location: connecter.php");
}
?>