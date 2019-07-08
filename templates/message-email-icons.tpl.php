<?php foreach ($icons as $icon): ?>
  <span class="fa fa-<?php print $icon['icon']; ?>" title="<?php print t($icon['title']); ?>"></span>
<?php endforeach; ?>
