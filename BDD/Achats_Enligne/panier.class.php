<?php
class panier {
	public function __construct()
	{
		if(!isset($_SESSION['panier']))
		{
			$_SESSION['panier']=array();
		}
	}

	public function add($IdArticle)
	{
		if(isset($_SESSION['panier'][$IdArticle]))
		{
			$_SESSION['panier'][$IdArticle]++;
		}
		else 
		{
			$_SESSION['panier'][$IdArticle]=1;

		}
		
	}

	public function del($IdArticle)
	{	
		if($_SESSION['panier'][$IdArticle]>0)
		{
			$_SESSION['panier'][$IdArticle]--;
		}
	}
}
?>